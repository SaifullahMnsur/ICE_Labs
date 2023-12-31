#include "SLL"

template <typename T>
SLL<T>::SLL() : head(nullptr), length(0) {}

template <typename T>
SLL<T>::~SLL()
{
    nodeSLL<T> *temp = head;
    while(temp != nullptr )
    {
        head = temp->next;
        delete head;
        temp = head;
    }
    std::cout << "Destrcted!\n";
}
template <typename T>
void SLL<T>::insert_back(T value)
{
    nodeSLL<T> *new_node = new nodeSLL<T>(value);
    if( new_node == nullptr )
    {
        std::cerr << "Error creating new node!\n";
        exit(1);
    }
    length++;
    if( head == nullptr )
    {
        head = new_node;
        return;
    }
    nodeSLL<T> *temp = head;
    while( temp->next != nullptr )
        temp = temp->next;
    temp->next = new_node;
    return;
}
template <typename T>
void SLL<T>::insert_front(T value)
{
    nodeSLL<T> *new_node = new nodeSLL<T>(value, head);
    if( new_node == nullptr )
    {
        std::cerr << "Error creating new node!\n";
        exit(1);
    }
    length++;
    head = new_node;
    return;
}
template <typename T>
void SLL<T>::insert(T value, size_t position)
{
    if( position == 1 )
    {
        insert_front(value);
        return;
    }
    if( position == length+1 )
    {
        insert_back(value);
        return;
    }
    if( position < 1 || position > length+1 )
    {
        std::cerr <<"Error position!\n";
        exit(2);
    }
    nodeSLL<T> *new_node = new nodeSLL<T>(value);
    if( new_node == nullptr )
    {
        std::cerr << "Error creating new node!\n";
        exit(1);
    }
    length++;
    nodeSLL<T> *temp = head;
    for( size_t i = 2 ; i < position ; i++ )
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return;
}
template <typename T>
void SLL<T>::print()
{
    nodeSLL<T> *temp = head;
    while(temp != nullptr )
    {
        std::cout << temp->data <<" ";
        temp = temp->next;
    }
    std::cout << "\n";
    return;
}

template <typename T>
size_t SLL<T>::size()
{
    return length;
}