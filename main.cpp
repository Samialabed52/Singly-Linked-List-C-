/**
 * A sample code of Creating C++ linked lists,
 * Including definitions the list node class and linked list class,
 * and how to create a blank linked list and a one-node linked list.
 *
 * Outline: understand the definition and structure of the linked
 * list and build a linked list based on it.
 */

#include <iostream>
#include <cstddef>
using std::cout;
using std::endl;


/* definition of the list node class */
class Node
{
    friend class LinkedList;
private:
    int value;  
    Node *pNext; 
    
public:
    /* Constructors with No Arguments */
    Node()
        : pNext(NULL) 
    { }
    
    /* Constructors with a given value */
    Node(int val)
        : value(val), pNext(NULL)
    { }
    
    /* Constructors with a given value and a link of the next node */
    Node(int val, Node *next)
        : value(val), pNext(next)
    {}
    
    /* Getters */
    int getValue() { return value; } 
    
    Node *getNext() { return pNext; } 
};

/* definition of the linked list class */
class LinkedList
{
private:
    /* pointer of head node */
    Node *pHead;
    /* pointer of tail node */
    Node *pTail;
    
public:
    /* Constructors with No Arguments */
    LinkedList();
    /* Constructors with a given value of a list node */
    LinkedList(int val);
    /* Destructor */
    ~LinkedList();
    
    /* Traversing the list and printing the value of each node */
    void traverse_and_print();

    void push_back(int val);
};

LinkedList::LinkedList()
{
    /* Initialize the head and tail node */
    pHead = pTail = NULL;
}

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    pHead = new Node(val); 
    pTail = pHead;
}

LinkedList::~LinkedList()
{
}

void LinkedList::traverse_and_print()
{
    Node *p = pHead; 
    
    /* The list is empty? */
    if (pHead == NULL) 
    {
        cout << "The list is empty" << endl;
        return ;
    }
    
    cout << "LinkedList: ";
    /* A basic way of traversing a linked list */
    while (p != NULL) /* while there are some more nodes left */
    {
        /* output the value */
        cout << p->value;
        /* The pointer moves along to the next one */
        p = p->pNext;
        cout << " "; //added space between node values
    }
    cout << endl;
}

void LinkedList::push_back(int val)
{
    //Creates a new node pointed to by p
    Node *p = new Node(val);
    
    //if the list is empty it will make the new node act as both the head and tail node
    if(pHead == NULL)
    {
        pHead = p; //head pointer points to new node
        pTail = p; //tail pointer points to new node
    }
    //if the list is not empty, the new node will act as the tail
    else
    {
        pTail->pNext = p; //current tail node now has a pointer that points at p  
        pTail = p; //p will now act as the tail node
    }
}

int main(int argc, const char * argv[])
{
    /* Create an empty list */
    LinkedList list1;
    cout << "Created an empty list named list1." << endl;
    /* output the result */
    cout << "list1:" << endl;
    list1.traverse_and_print();
    
    /* Create a list with only one node */
    LinkedList list2(10);
    cout << "Created a list named list2 with only one node." << endl;
    /* output the result */
    cout << "list2:" << endl;
    list2.traverse_and_print();

    /*your testing code here*/
    for (int i = 0 ; i < 10; i++)
    {
        list2.push_back(i);
    }
    list2.traverse_and_print();
    
    return 0;
}


