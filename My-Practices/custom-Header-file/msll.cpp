#include <iostream>
#include "ICE/ASSIGNMENTS"
using namespace std;
#ifdef SAIFBRO
#define done cerr << "Line " << __LINE__ << " is done" << endl;
#endif
int main()
{
    SLL<int> myList;
    myList.insert_front(10);
    myList.insert_front(20);
    myList.insert_front(30);

    myList.print();

    myList.insert(50, 1);
    myList.print();
    myList.insert(60, 5);
    myList.print();
    myList.insert(100, 5);
    myList.print();
    myList.size();
    done;
    return 0;
}