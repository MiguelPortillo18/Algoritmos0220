// Inserting in asc order is same as 1.cpp, this examples contemplates desc inserting
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "LinkedList.h" // Push back is not used for the purpose of the excercise
using namespace std;

//Function prototypes
void traverseList(node*);
void insertElement(T, node**);
int getRandom();

int main(void) {
    //initialized seed to generate random numbers
    srand(time(NULL));

    //Initialized nodes in NULL
    node* pList = NULL;

    //Loop that contains insertion elements on the list
    for(int i = 0; i < 1500; i++)
        //The function recieves another function that generates random numbers
        insertElement(T(rand() % 500), &pList);

    //Show results
    traverseList(pList);

    return 0;
}

//Function that generates random numbers
int getRandom(void) {
    return rand() % 1500 + 1;
}

//Function that travels the elements of a list
void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}

//Insertion function
void insertElement(T data, node** pList) {
    node* n = new node;
    n->info = data;

    //If clause to check the correct insertion of
    //randomly numbers

    //Checking that the new element that will be inserted
    //is greater to the existing one

    if(!*pList || (*pList)->info < n->info){
        n->next = *pList;
        *pList = n;
    }
    else {
        node* current = *pList;

        //Checking that the new element that will be inserted
        //is smaller than the existing one
        while(current->next && current->next->info > n->info)
            current = current->next;

        //Assigning order into the insertion
        n->next = current->next;
        current->next = n;
    }
}

