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
    
void insert( int time, string name)
    {
        node *tmp, *q1;
        
        tmp = new node;
        tmp->name = name;
        tmp->time = time;
        
        if (front == NULL || time < front->time)
        {
            tmp->next = front;
            front = tmp;
        }
        
        else
        {
            
            q1 = front;
            
            while (q1->next != NULL && q1->next->time <= time)
                
            q1=q1->next;
            
            tmp->next = q1->next;
            
            q1->next = tmp;
            
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
* Print time Queue
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
 * Peek->Peek and grab.
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
    //ask user name
    cout << "Enter file name: ";

    //input name
    cin >> input;

    //open the file
    readFile.open(input);

    if(readFile.is_open())
        {
            //cout << "Reading file\n";

            //get number of people
            readFile >> numPeople;
            
            //read in all names from file
            for(int i =0;  i < numPeople;  i++)
                {
                    //read file of time
                    readFile >> time >> name;
                    //insert
                    procQ.insert(time, name);
                }
        }
    
        //closes file
        readFile.close();
        cout<<"Closing file\n";
   
//------------------------------------------------
    //this is the discrete time simulation of: 35 seconds.
    for(int i=1; i <= 35; i++)
        {
            //to easier track current time
            int timeStamp = i;
       
            cout << "t = "<< i << endl;
            cout << "-------------------------"<<endl;
            cout << endl;
        
//Mr. Bones’ Wild Ride
//-------------------------
        
//calculation
waitTime1 = 10 - i % 10;

        if(waitTime1 == 10)
            {
                //if ride runs with nobody in the line
                if(wildBones.empty()== true)
                    {
                        cout <<"The Mr. Bones wild Ride is idle\n";
                    }
            
            //when a customer has been sorted into the ride
            else
                cout << "         " << "Mr. Bones' Wild Ride is now boarding: ";
                wildBones.display();
                cout << endl;
            
                //delete two riders
                wildBones.del();
                wildBones.del();
                maxNumBone =0;
            }
    
        // at end of cycle restart
        if(waitTime1 == 1)
            {
                waitTime1 = waitTime1 + 10;
            }
        
         //if line is full add cycle to wait time
        else if(maxNumBone == 2)
            {
                waitTime1 = waitTime1 + 10;
            }
        

//the No-Fun House
//-------------------------

//calculation
waitTime2 = 7 - (i % 7);
        
        if(waitTime2 == 7)
            {
                //if ride runs with nobody in the line

                if(no_funHouse.empty() == true)
                    {
                        cout <<"The No-Fun House is idle\n";
                    }
                
                //when a customer has been sorted into the ride
                else
                    cout << "       " << "The No-Fun House is now boarding: ";
                    no_funHouse.display();
                    cout << endl;
                
                    no_funHouse.del();
                    no_funHouse.del();
                    no_funHouse.del();
                    maxNumFun = 0;
            }
        
        // at end of cycle restart
        if(waitTime2 == 1)
            {
                waitTime2 = waitTime2 + 7;
            }
        
        //if line is full add cycle to wait time
        else if(maxNumFun == 3)
            {
                waitTime2 = waitTime2 + 7;
            }
//-------------------------
        
//SORTING
//at one se ahead of the current time, if next person in the processing queue has a number == to one sec ahead of now, start sorting.
        
            //IF WE FIND SOMEONE WITH A MATCHING TIME
            if( procQ.peekTime() == timeStamp )
                {
                    int aTime;
                    string aName;

                    aTime = procQ.peekTime();
                    aName = procQ.peekName();
                
                    cout << "       " << aName << " is choosing between Mr. Bones' Wild Ride (wait time = " << waitTime1 << " minutes) and The No-Fun House (wait time = " << waitTime2 << " minutes).\n";
                
                    //if the first line is shorter than the second
                if(waitTime1 < waitTime2)
                    {
                    
                        //add
                        wildBones.insert(aTime, aName);
                    
                        cout <<  "      " << aName << " has entered the line for Mr. Bones' Wild Ride.\n";
                        cout << endl;
                    
                        //delete old
                        procQ.del();
                        
                        //increment
                        maxNumBone++;
                    }
                    
                //if the second line is shorter than the first
             else if(waitTime2 < waitTime1 )
                {
                    
                    no_funHouse.insert(aTime, aName);
                    
                    cout <<  "       " <<aName << " has entered the line for The No-Fun House.\n";
                    cout << endl;
                    
                    //delete old
                    procQ.del();
                    
                    //increment
                    maxNumFun ++;
                }
            }
        
        //default print 1
            cout << endl;
            cout << "       Mr. Bones' Wild Ride line: ";
            
            //print line
        wildBones.display();
            
            cout << endl;
            cout << "       The No-Fun House line: ";
            
            //print line
        no_funHouse.display();
            cout << endl;
            cout << "-------------------------"<<endl;
            cout << endl;
            cout << endl;
    }
}
