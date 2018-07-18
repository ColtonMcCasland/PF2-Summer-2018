// Name : Colton McCasland
//        Walter Niblock
//
// Assignment 5 (ADT(s) - Priority Queue Implementation)
//------------------------------------------------
/*
 * C++ Program to Implement Priority Queue
 */
//------------------------------------------------

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
//------------------------------------------------
/*
* Node Declaration
*/
//------------------------------------------------
struct node
{
    int rank;
    int priority;
    string name;
    struct node *next;
};
//------------------------------------------------
/*
 * Class time Queue
 */
//------------------------------------------------

class pQueue
{

private:
    node *front;

public:
    pQueue()
    {
        front = NULL;
    }

//------------------------------------------------
/*
* Insert into time Queue
*/
//------------------------------------------------

void insert( string name, int priority, char rank)
{
        node *tmp, *q;

        //Temporary (new) Node to insert
        tmp = new node;
        tmp->name = name;
        tmp->priority = priority;

        //Check if no nodes exist or if temp node Priority
        //is less than the queue's front node.
        //(Front -> Back is Low -> High Priority)
        if (front == NULL || (priority < front->priority && rank < front->rank))
        {
            tmp->next = front;
            front = tmp;
        }

        else
        {
            q = front;

            //Find Spot in Queue based on priority of node
            while(q->next != NULL && priority >= q->next->priority  )
                q = q->next;

                //Reassign ptrs
                tmp->next = q->next;
                q->next = tmp;

        }
}
//------------------------------------------------
/*
* Delete from time Queue
*/
//------------------------------------------------
 //UNDER CONSTRUCTION///////////////////////////////////
void del()
    {
        node *tmp;
        //if empty print nothing
        if(front == NULL)
                cout<<"Queue underflow\n";

        else
        {
            tmp = front;
            cout << "Deleted item is: " << tmp->name << endl;
            front = front->next;

            free(tmp);
        }
    }
//------------------------------------------------
/*
* Print Queue
*/
//------------------------------------------------
void display()
    {
        node *ptr;

        //pointers
        ptr = front;

        //if empty print nothing
        if (front == NULL)
            cout<<"Empty";

        else
        {
            cout << "Queue is: \n";
            cout << setw(5) << "Priority" << " | " << "Name\n";
            while(ptr != NULL)
            {
                cout << setw(5) << ptr->priority << " | " << ptr->name << endl;

                ptr = ptr->next;
            }
        }
    }
};

//------------------------------------------------
/*
 * Main
 */
//------------------------------------------------
int main()
{

    int choice, priority, rank;
    string name;
    pQueue pq;
    do
    {
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Display\n";
        cout<<"4. Quit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Input the name to be added in the queue : ";
                cin>>name;
                cout<<"Enter its priority : ";
                cin>>priority;
                pq.insert(name, priority);
                break;

            case 2:
                pq.del();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                break;

            default :
                cout<<"Wrong choice\n";
        }
    }
    while(choice != 4);
    return 0;
}
