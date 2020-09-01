#include <time.h>
#include <cstdlib>
#include <iostream>
//Contains information about node structure and functions thaht insert
//elements into a list
#include "LinkedList.h"
using namespace std;

//Function prototypes
void traverseList(node*);
void traverseListWithLimit(node*, int);

int main(void) {
    //Initializing seed that generates random numbers
    srand(time(NULL));

    //int variables that will be used in the program
    int quantity = 0, limit = 0;

    //Initializing nodes
    node* list = NULL;

    //Inserting quantity of elements in list
    cout << "Quantity of elements: "; cin >> quantity;

    //Inserting process
    for(int i = 0; i < quantity; i++)
        pushBack(T(rand() % 1000), &list);

    //List before insert the value to exceed
    cout << "List content:" << endl;
    traverseList(list);

    //Insert the number(limit)
    cout << endl << "Value to exceed: "; cin >> limit;

    //List after insertion of value to exceed
    cout << endl << "Values more than " << limit << endl;
    traverseListWithLimit(list, limit);

    return 0;
}

//Function that travel elements in list and show them
void traverseList(node* list){
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}

//Function that travel elements in list, but recieves a number (limit), this will be the reference
//to show the elements greater than that number
void traverseListWithLimit(node* list, int limit) {
    if(list) {
        if(list->info.data > limit){
            cout << list->info.data << endl;
        }
        traverseListWithLimit(list->next, limit);
    }
}