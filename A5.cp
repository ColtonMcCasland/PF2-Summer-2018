// Name : Colton McCasland
// Assignment 2 (Queues)
//------------------------------------------------
/*
 * C++ Program to Implement PRIORITY Queue
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
    int time;
    string name;
    struct node *next;
};
//------------------------------------------------
/*
 * Class time Queue
 */
//------------------------------------------------

class time_Queue
{
    
private:
    node *front;
    
public:
    time_Queue()
    {
        front = NULL;
    }
//------------------------------------------------
/*
* Insert into time Queue
*/
//------------------------------------------------
///////////////////UNDER CONSTRUCTION///////////////////////////////////////////////////////////
    
    
void insert( int time, string name)
    {
        node *tmp, *q1;
        
        tmp = new node;
        tmp->name = name;
        tmp->time = time;
        
        if ( empty() == true)
        {
            tmp->next = front;
            front = tmp;
        }
        
    }
//------------------------------------------------
/*
* Delete from time Queue
*/
//------------------------------------------------
    
void del()
    {
        node *tmp;
        //if empty print nothing
        if(front == NULL)
                cout<<"";
        
        else
        {
            tmp = front;
            
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
            cout<<"";
        
        else
        {
            while(ptr != NULL)
            {
                cout << ptr->name <<" ";
              
                ptr = ptr->next;
            }
        }
    }

//------------------------------------------------
/*
 * Peek->and grab.
*/
//------------------------------------------------
int peekTime()
    {
        
        if(front == nullptr)
            {
                return NULL;
            }
        
        else
            return front->time;
    }
    
string peekName()
    {
        return front->name;
    }
    
bool empty()
    {
        return front == nullptr;
    }
    
};

//------------------------------------------------
/*
 * Main
 */
//------------------------------------------------

int main()
{
    //prolly scratch all this vvv...
    
    
    //ints
    int maxNumBone = 0, maxNumFun = 0;
    int time = 0;
    int numPeople;
    int waitTime1, waitTime2;
    //strings
    string name;
    string input;
    ifstream readFile;
    //queues
    time_Queue wildBones, no_funHouse, procQ;

//---------------------------

wildBones.insert(aTime, aName);
//
//                        cout <<  "      " << aName << " has entered the line for Mr. Bones' Wild Ride.\n";
//                        cout << endl;
//
//                        //delete old
//                        procQ.del();
//
//                        //increment
//                        maxNumBone++;
//                    }
//
//                //if the second line is shorter than the first
//             else if(waitTime2 < waitTime1 )
//                {
//
//                    no_funHouse.insert(aTime, aName);
//
//                    cout <<  "       " <<aName << " has entered the line for The No-Fun House.\n";
//                    cout << endl;
//
//                    //delete old
//                    procQ.del();
//
//                    //increment
//                    maxNumFun ++;
//                }
//            }
//
//        //default print 1
//            cout << endl;
//            cout << "       Mr. Bones' Wild Ride line: ";
//
//            //print line
//        wildBones.display();
//
//            cout << endl;
//            cout << "       The No-Fun House line: ";
//
//            //print line
//        no_funHouse.display();
//            cout << endl;
//            cout << "-------------------------"<<endl;
//            cout << endl;
//            cout << endl;
    }
}
