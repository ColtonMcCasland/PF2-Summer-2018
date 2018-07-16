// Name : Colton McCasland
// Assignment 2 (Queues)
//------------------------------------------------
/*
 * C++ Program to Implement time Queue
 */
//------------------------------------------------

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;
//------------------------------------------------
/*
* Node Declaration
*/
//------------------------------------------------

struct node
{
    
    
    //old
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

void insert( string name, int priority)
{
        node *tmp, *q;
        
        tmp = new node;
        tmp->name = name;
        tmp->priority = priority;
        
        if ( front == NULL || priority < front->priority)
        {
            tmp->next = front;
            front = tmp;
        }
        else
        {
            q = front;
            while(q->next != NULL && q->next->priority <= priority)
                q=q->next;
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
            cout << "Queue is: " << endl;
            cout << "Name       Priority\n";
            while(ptr != NULL)
            {
                cout << ptr->name <<"           "<< ptr->priority << endl;
              
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
    
    int choice, priority;
    string name;
    pQueue pq;
    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : ";
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
