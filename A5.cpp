// Name : Colton McCasland
//        Walter Niblock
//        Joseph Cantrell
//
// Assignment 5 (ADT(s) - Priority Queue Implementation)
//------------------------------------------------
/*
 * C++ Program to Implement Priority Queue
 */
//------------------------------------------------

#include <iostream>
#include <fstream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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

    //----------------------------------------------------------------------------------------------------------------------------
    /*
     * Name: insert
     * Input: String name, Int Priority, Int rank
     * Return: Nothing
     * Function: When called, inserts the new User by rank, then priority into the queue
     */

void insert( string name, int priority, int _rank)
{
    node *tmp, *q;

    bool priorityCheck = false;
    bool rankCheck = false;

    //Temporary (new) Node to insert
    tmp = new node;
    tmp->name = name;
    tmp->priority = priority;
    tmp->rank = _rank;

    //Check if no nodes exist or if temp node Priority
    //is less than the queue's front node.
    //(Front -> Back is Low -> High Priority)
    if (front == NULL || (priority <= front->priority && _rank <= front->rank))
        {
            tmp->next = front;
            front = tmp;
        }

        else
        {
            q = front;
            //Find Spot in Queue based on Rank of node, Then priority
            while(q->next != NULL && (_rank >= q->next->rank))                              // If the current rank is lower than the next rank in line, continue
                if(_rank > q->next->rank && !rankCheck)                                     // If the rank is larger than the next one
                    q = q->next;                                                            // Move to the next node, sorting by rank THEN priority
                else
                    if((priority > q->next->priority) )                                     // (Rank should be sorted at this point) If the priority is larger than the next one
                        q = q->next;                                                        // Move to the next node
                    else                                                                    // Else, the priority is smaller
                        break;                                                              // And it must be sorted, break the loop

            //Reassign ptrs
            tmp->next = q->next;
            q->next = tmp;

        }
    }

    //----------------------------------------------------------------------------------------------------------------------------
    /*
     * Name: del
     * Input: Nothing
     * Return: Nothing
     * Function: When called, this deletes the top member of the queue
     */
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

    //----------------------------------------------------------------------------------------------------------------------------
    /*
     * Name: display
     * Input: Nothing
     * Return: Nothing
     * Function: When called, Displays the entire queue sorted by rank, then priority
     */
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
        cout << setw(5) << "Priority | " << "Name \t| " << "Rank\n";
        while(ptr != NULL)
        {
            cout << setw(5) << ptr->priority << "    | " << ptr->name << "\t | ";
            if(ptr->rank == 1)
                cout << "General" << endl;
            else if(ptr->rank == 2)
                cout << "Sergeant" << endl;
            else
                cout << "Private" << endl;

            ptr = ptr->next;
        }
    }
}
};

    //----------------------------------------------------------------------------------------------------------------------------
    /*
     * Main
     */

int main()
{
    int choice, priority, rank;
    string name, prevName;
    pQueue pq;
    do
    {
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Display\n";
        cout<<"4. Quit\n";
        cout<<"5. Load from a file\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Input the name to be added in the queue : ";
                cin >> name;
                cout<<"Enter their rank : ";
                cout << "\n1: General\n2: Sergeant\n3: Private\n";
                cin >> rank;
                while(rank != 1 && rank != 2 && rank != 3)
                {
                    cout << "That is not a rank, try again: ";
                    cin >> rank;
                }
                //cin >> rank;
                cout<<"Enter their priority (1 - 5): ";
                cin >> priority;
                while(priority != 1 && priority != 2 && priority != 3 && priority != 4 && priority != 5 )
                {
                    cout << "That is not an allowed Priority, Try again: ";
                    cin >> priority;
                }
                pq.insert(name, priority, rank);
                break;

            case 2:
                pq.del();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                break;

            case 5:                 // Case for opening up a file with all of the information needed
            {
                fstream fin;                                                    // Creating the fstream named fin
                string fileName = "";                                           // Creating a string to hold the filename
                cout << "Input the file name please: ";                         // Asking the user for the file name
                cin >> fileName;                                                // Assigning the value from the user to the filename string
                fin.open(fileName.c_str());                                     // Attempt to open the file
                if(fin.fail())                                                  // If the file cannot be opened,
                {
                    cout << "Unable to open filename " << fileName << endl;     // Print and error screen
                    break;                                                      // Leave the program
                }
                prevName = "";                                                  // Set previous name to blank   (default values)
                name = "";                                                      // Set name to blank            (default values)
                rank = 0;                                                       // Set rank to 0                (default values)
                priority = 0;                                                   // Set priority to 0            (default values)
                fin >> name >> rank >> priority;                                // get the first person from the text file and input into the correct variables
                pq.insert(name,priority,rank);                                  // Insert the first person into the queue
                while(name != prevName)                                         // While the current name does not equal the previous name, continue (end of the file)
                {
                    prevName = name;                                            // Set previous name equal to the current name
                    fin >> name >> rank >> priority;                            // get the next person form the text file and input into the correct variables
                    pq.insert(name,priority,rank);                              // Insert the current person and their variables into the queue
                }
                pq.display();                                                   // Print out the current queue
                cout << endl;                                                   // Create a new line
                fin.close();                                                    // Close the text file
                break;                                                          // Leave this case statement
            }

            default:
                cout<<"Wrong choice\n";
        }
    }
    while(choice != 4);
    return 0;
}

