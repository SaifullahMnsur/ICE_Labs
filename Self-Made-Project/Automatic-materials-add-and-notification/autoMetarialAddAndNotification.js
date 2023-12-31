function onFormSubmit(event) {
    var historySheetId = 'ADD_YOUT_GOOGLE_SHEET_ID'; // store when code executed
    var historySheetFile = SpreadsheetApp.openById(historySheetId);
    var sheet = historySheetFile.getSheetByName('Sheet1');
  
    var timestamp = new Date();
    var currTime = Utilities.formatDate(timestamp, Session.getScriptTimeZone(), 'HH:mm:ss');
  
    try {
      var formID = FormApp.getActiveForm().getId(); // get the id of current form
      var form = FormApp.openById(formID); // the form
      var formResponses = form.getResponses(); // get all user responses of the form
      var responseCount = formResponses.length; // get the number of responses
  
      // if there is any response
      if (formResponses.length > 0) {
        // var lastResponse = formResponses[responseCount - 1].getGradableItemResponses(); // get the latest response
        var lastResponse = formResponses[responseCount - 1].getItemResponses(); // get the latest response
        var courseItemResponse = lastResponse[0]; // get the course item
        var courseName = courseItemResponse.getResponse(); // get the response of course item
        var courseCode = firstWord(courseName); // extract the first word as course code
  
        var sectionItemResponse = lastResponse[1]; // get the section item
        var section = sectionItemResponse.getResponse(); // get the response of section
        if (courseCode[courseCode.length - 1] === '2' || section === 'None (Labs & Books)' || courseCode === 'MATH2221') // if the section is not A or B it must be blank
          section = "";
  
        Logger.log('course: ' + courseCode);
        Logger.log('section: ' + section);
  
        var folderId = ''; // assume folder id
        var folder = ''; // assume folder
        if (courseCode === 'MATH2221') {
          folderId = '1-pYh4A_mOOVnQFPrWqX61WOamqWOPYgH'; // math2221 folder id
          folder = DriveApp.getFolderById(folderId);
        } else if (courseCode === 'Books') {
          folderId = '18dOc-Zpaf3fAsAdQ9JxlhnkfxCCT9NeD'; // books folder id
          folder = DriveApp.getFolderById(folderId);
        } else {
          var mainFolderId = getSemesterFolderId(courseCode); // get the folder id of that semester
          Logger.log(mainFolderId);
          folderId = getCourseSectionFolder(mainFolderId, courseName, section); // get the folder id of desired course
          folder = DriveApp.getFileById(folderId); // get the folder
        }
        Logger.log('Return folder id: ' + folderId);
        Logger.log('Returned folder: ' + folder);
  
        var destinationFolder = DriveApp.getFolderById(folderId); // set the folder as destination folder
        var fileItemResponse = lastResponse[2].getResponse(); // get the upload file items
        Logger.log('all responses:' + fileItemResponse);
  
        var fileItemString = fileItemResponse.toString(); // convert fild id object to string
        var fileIDs = fileItemString.split(','); // split the ids into separate pieces
  
        for (var i = 0; i < fileIDs.length; i++) {
          Logger.log('fileIDs: ' + fileIDs[i]);
          var file = DriveApp.getFileById(fileIDs[i]); // get the file
          Logger.log(file.getName() + ' ' + fileIDs[i]);
          file.moveTo(destinationFolder); // move the file to destination
        }
        var uploaderName = lastResponse[3].getResponse();
        var materialComment = lastResponse[4].getResponse();
        notifyEveryone(courseName, uploaderName, materialComment, folderId); // notify everyone about the material
        sheet.appendRow([currTime, uploaderName, materialComment, courseCode, section ]);
      } else {
        Logger.log('No response found');
      }
    } catch (error) {
      Logger.log('Error: ' + error.toString());
    }
  }
  
  function notifyEveryone(courseName, nameResponse, materialComment, folderId){
    var sheetId = 'INSERT_YOUR_GOOGLE_SHEET_ID'; // spread sheet id where email of recipants are stored
    var spreadsheet = SpreadsheetApp.openById(sheetId); // get the sheet file
    var sheet = spreadsheet.getSheetByName('Sheet1'); // get the active sheet of the sheet
  
    var range = sheet.getRange(1, sheet.getLastColumn(), sheet.getLastRow(), 1); //  setup up the range of email
    var values = range.getValues(); // get all the emails
    var emailAddress = '';
    // merge all the emails by comma
    for (var i = 1; i < values.length; i++) {
      if( i > 1 )
        emailAddress = emailAddress + ',' + values[i][0];
      else
        emailAddress = values[i][0];
    }
    Logger.log(emailAddress);
  
    var folder = DriveApp.getFileById(folderId); // get the folder where files were moved
    var folderLink = folder.getUrl(); // get the url of that folder
    Logger.log('folder link: ' + folderLink);
    // write the message to be sent
    var message = 'Some new materials for <strong>' + courseName + '</strong> has been added to the drive by <strong>' + nameResponse + '</strong><br><br>Folder link: <a href="' + folderLink + '">' + folderLink + '</a><br>Material comment: ' + materialComment + '<br><br>This system is automated and sends a message to everyone once anyone adds new materials.';
    Logger.log('Message: ' + message);
    var subjectMessege = 'ICE 21: New material added';
  
    // send email to everyone
    MailApp.sendEmail({
      subject: subjectMessege,
      htmlBody: message,
      bcc: emailAddress,
    });
  }
  
  function getCourseSectionFolder(semFolderId, courseName, section) {
    var semFolder = DriveApp.getFolderById(semFolderId); // get the semester's folder id
  
    var searchFor = '';
    var sectionName = '';
  
    // set if it is lab or theory
    if (section === '') {
      searchFor = 'Lab';
      sectionName = 'Section ' + section;
    } else {
      searchFor = 'Theory';
      sectionName = 'Section ' + section;
    }
    Logger.log(sectionName + ' ' + searchFor);
  
    var tlFolders = semFolder.getFoldersByName(searchFor); // search for theory/lab folder inside the semester folder
    var tlFolder = '';
    if (tlFolders.hasNext()) {
      tlFolder = tlFolders.next(); // if the folder is available then store it
    } else {
      tlFolder = semFolder.createFolder(searchFor); // if the folder is not available then create a folder
    }
    Logger.log('tlfolder: ' + tlFolder);
  
    var courseFolders = tlFolder.getFoldersByName(courseName); // search for the course inside theory/lab folder
    var courseFolder = '';
    if (courseFolders.hasNext()) {
      courseFolder = courseFolders.next(); // if the folder is available store it
    } else {
      courseFolder = tlFolder.createFolder(courseName); // if the store is not available then create a folder
    }
    Logger.log('Course folder: ' + courseFolder);
    if (section === '') { // if the section part is empty which means it is lab course then return the folder id
      return courseFolder.getId();
    }
    //if it is theory course then find section folder
    var sectionFolders = courseFolder.getFoldersByName(sectionName); // search for the section inside course folder
    var sectionFolder = '';
    if (sectionFolders.hasNext()) {
      sectionFolder = sectionFolders.next(); // if the section folder is available then store it
    } else {
      sectionFolder = courseFolder.createFolder(sectionName); // if the section folder is not available then create it
    }
    Logger.log('Section folder: ' + sectionFolder);
    return sectionFolder.getId(); // return the section folder id
  }
  
  function getSemesterFolderId(courseCode) {
    var len = courseCode.length - 1;
    if (courseCode[len - 3] === '2' && courseCode[len - 2] === '2') // 2-2 semester folder id
      return '1dbIDI473fskhf6oxWbB531zqBZzlkdW-';
    if (courseCode[len - 3] === '3' && courseCode[len - 2] === '1') // 3-1 semester folder id
      return '1svmWF3PQrPU0JvTXVHvrjPN8O83fXdoZ';
    if (courseCode[len - 3] === '3' && courseCode[len - 2] === '2') // 3-2 semester folder id
      return '1ULaTkcx-jUDDWxcIp4tjNKOnabjJHIjo';
    if (courseCode[len - 3] === '4' && courseCode[len - 2] === '1') // 4-1 semester folder id
      return '1YhtACIvJ9nQb6L3bgFhHqltgMm-tKeKN';
    if (courseCode[len - 3] === '2' && courseCode[len - 2] === '2') // 4-2 semester folder id
      return '1SurU19a0ikf1jU7Krl1y0NhlEvAqTkIf';
    return '';
  }
  
  function firstWord(inputString) {
    if (inputString) {
      var words = inputString.split(" ");
      return words[0];
    } else {
      return "";
    }
  }