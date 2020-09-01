#include <iostream>
//Contains information about node structure and functions thaht insert
//elements into a list
#include "LinkedList.h"  
using namespace std;

//Function prototype
T getAt(int, node*);

int main(void) {
    int pos = 0;

    //Initialzing node
    node* list = NULL;

    //function that inserts elements into a list like a queue
    pushBack(T(3), &list);
    pushBack(T(5), &list);
    pushBack(T(7), &list);     
    pushBack(T(9), &list);
    pushBack(T(11), &list);

    //Recieving position of the list
    cout << "Node position: "; cin >> pos;

    //Try-catch clause used to check that the requested position exists
    //and show it
    try{
        T e = getAt(pos, list);
        cout << "Value of position #" << pos << ": " << e.data << endl;
    }
    catch(...){
        cout << "Invalid position." << endl;
    }

    return 0;
}

//Function that recieves a list and a position of it
T getAt(int pos, node* list) {
    if(list) {
        if(pos == 0) {
            return list->info;
        }
        else
            return getAt(pos - 1, list->next);
    }
    else {
        throw exception();
    }
}