#include <iostream>
//Contains information about node structure and functions thaht insert
//elements into a list
#include "LinkedList.h"  
using namespace std;

//function prototype
int multiplyNodes(node*); 

int main(void) {
    node* list = NULL;

    //function that inserts elements into a list like a queue
    pushBack(T(3), &list);
    pushBack(T(6), &list);
    pushBack(T(9), &list);
    pushBack(T(12), &list);
    pushBack(T(15), &list);

    //Show the result
    cout << "Calculated values: " << multiplyNodes(list) << endl;

    return 0;
}

//This function recieves a list and with the information of every node
//this will be multiplied making a recursive call of these function that will
//recieve the next node
int multiplyNodes(node* l) {
    return l != NULL ? l->info.data * multiplyNodes(l->next) : 1;
}