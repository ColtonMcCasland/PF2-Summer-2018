//
//  main.cpp
//  PF2 A1
//
//  Created by Colton McCasland on 6/9/18.
//  Copyright © 2018 Colton McCasland. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
typedef int InfoType;

//passenger class
class Passenger
{        
public:
    string firstName;
    string lastName;
    Passenger* next;
};

class Manifest
{
    
private:
    // A linked list node
    struct Node
    {
        string m_firstName;
        string m_lastName;
        Node *next;
        Node *last;
    };
    Node *head;
    
public:
    InfoType value;
    Manifest();
    Manifest(const Manifest &other);
    ~Manifest();
   
    void bookPassenger( string firstName, string lastName);
    bool confirmPassenger( string firstName, string lastName);
    bool cancelPassenger(string firstName, string lastName);
    
    bool isEmpty();
    void printPassengers(const bool printAddresses);
};

Manifest::Manifest() //empty template
    {
        head = nullptr;
    }
    
Manifest::Manifest(const Manifest &other)  //copy constructor
    {
         //Create a dummy node in our new list
        Node *newNode = new Node;
        head = newNode;
        
        //Make a pointer to the beginning of the list we want to copy
        Node* ptr = other.head;

        //While that pointer is valid
        while (ptr != nullptr)
        {
            //Make a new blank node in our list
            newNode->next = new Node;
            newNode = newNode->next;
            
            //Copy the current node from the copy list
            newNode->m_firstName = ptr->m_firstName;
            newNode->m_lastName = ptr->m_lastName;
            newNode->next = nullptr;
        
            //Advance the pointer in the copy list
            ptr = ptr->next;
        }
        //Delete that dummy node we created at the beginning
        newNode = head;
        head = newNode->next;
        delete newNode;
    }
    
Manifest::~Manifest()// destructor
    {
        //Keep deleting the head until there's nothing left
        while(head != nullptr)
        {
            Node* ptr = head;
            head = head->next;
            delete ptr;
        }
    }

    bool Manifest::isEmpty()
    {
        //Check if the head is null
        return head == nullptr;
    }
    
    
    //for adding passenger
void Manifest::bookPassenger( string firstName, string lastName)
    {
        //create node we are inserting
        Node *newNode = new Node();
        newNode->next = nullptr;
        
        //pointers
        Node* current = head;
        Node* previous = head;
        //data
        newNode->m_firstName =  firstName;
        newNode->m_lastName  =  lastName;
        
        // if node isnt empty
        while(current != nullptr && (current->m_lastName < newNode->m_lastName))
        {
            previous = current;
            current = current->next;
        }
        
        //error check for same last names but comparing by firstname
        while(current != nullptr && (current->m_lastName == newNode->m_lastName))
        {
            if(current->m_firstName < newNode->m_firstName)
            {
                previous = current;
                current = current->next;
            }
        }
        
        //if empty set normal
        if(isEmpty())
        {
            head = newNode;
        }
        //else sort new node
        else
        {
        previous->next = newNode;
        newNode->next =current;
        }
  }
    
    //canceling booking
bool Manifest::cancelPassenger(string firstName, string lastName)
    {
        Node* current = head;
        Node* previous = head;
        
        //Advance current and previous until we find the node or we search the whole list
        while(current != nullptr && current->m_firstName != firstName && current->m_lastName != lastName)
        {
            previous = current;
            current = current->next;
        }
        
        //If current is null, we searched the whole list and found nothing (or the list was empty)
        if(current == nullptr)
            return false;
        
        //If we're deleting the head, update the head. Else, reroute prev->next
        if(current == head)
            head = head->next;
        else
            previous->next = current->next;
        
        //It is now safe to delete the node
        delete current;
        
        return true;
    }

    //does not correctly check to see if person already exists
    //confirm/search a booking
bool Manifest::confirmPassenger( string firstName, string lastName)
    {
         //Create a pointer to the head
        Node* ptr = head;
        
        //While the pointer is valid advance the pointer
        while ( ptr != nullptr && !(ptr->m_firstName == firstName && ptr->m_lastName ==  lastName))
            ptr = ptr->next;
        
        //If we found the node, this expression will be true. Otherwise, false.
        return ptr != nullptr;
    }

    //DOES NOT PRINT CORRECTLY
void Manifest::printPassengers(const bool printAddresses)
{
    //if empty do nothing
    if(isEmpty())
        return;
    
    //make pointer to head
    Node* ptr = head;
    
        while(ptr != nullptr)
        {
            if(printAddresses)
                cout << ptr->m_firstName <<" "<< ptr->m_lastName << ptr->next << " ->";
            
            else
                cout << ptr->m_firstName << " " << ptr->m_lastName << " -> ";
            
            ptr = ptr->next;
        }
    cout << "X\n";
}

int main()
{
    bool printAddresses = false;
    string input;
    string a,b;
    int commands;

    //and assign inputs to correct variables
    ifstream readFile;
    //ask user name
    cout << "Enter file name: ";
    //store name
    cin >> input;
    //let readFile find the file
    readFile.open(input);

//error check
if(readFile.is_open())
{
        cout << "Reading file..." << endl;

        //get number of commands to execute from file
         readFile >> commands;

    //object for class
    Manifest Passenger;

    //select action
    for(int i =0;  i < commands + 1;  i++)
    {
        int c;
        string a,b;

        //read commands
        readFile >> c;

        if(c == 1)
        {
                //read
                readFile >> a >> b;

                //confirm name isnt there already
                //if not already made, will make and put into list.
            if(Passenger.confirmPassenger(a,b) == false)
                {
                //Add a passenger.
                Passenger.bookPassenger(a,b);
                cout << "Booked " << a << " " << b << endl;
                }

                //if person is already booked and inside manifest
            else if(Passenger.confirmPassenger(a,b) == true)
                {
                cout << "Cannot book; Passenger " << a << " " << b <<" already booked;" << endl;
                }
            }

            //Cancel a passenger.
            else if(c == 2)
            {
                
            //read
            readFile >> a >> b;

            if(Passenger.confirmPassenger(a,b) == true)
                {
                    Passenger.cancelPassenger(a,b);
                    cout << "Cancel booking for " << a << " " << b << endl;
                }

            else if(Passenger.confirmPassenger(a,b) == false)
                {
                    cout <<"could not cancel booking for passenger " << a  << " " << b << " Passenger not found" << endl;
                }
            }

            //Confirm a passenger's booking.
            else if(c == 3)
            {
                
            //read
            readFile >> a >> b;

            if(Passenger.confirmPassenger(a,b) != false)
                {
                    //when true
                    cout << "Confirmed." << endl;
                }
            else if(Passenger.confirmPassenger(a,b) == false)
                {
                    //when false
                    cout << "Passenger " << a << " "<< b << " was not found" << endl;
                }
            }

            //Print the list.
            else if(c == 4)
            {
                
                cout << "Printing passengers:" << endl;
                Passenger.printPassengers(printAddresses);
            }

            //Quit.
            else if(c==5)
            {
                break;
            }
    }
}
    else
        //closes file
         readFile.close();
    }


