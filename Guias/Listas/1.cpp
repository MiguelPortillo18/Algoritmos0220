#include <iostream>
#include <time.h>
#include <cstdlib>
#include "LinkedList.h" //Contains information about list structure
using namespace std;

//Function prototypes
int getRandom(void);
template<class e>
void insertElement(e, node**);
void transferElements(node*, node**);
void traverList(node*);

int main(void) {
    //initialized seed to generate random numbers
    srand(time(NULL));

    //Initialized nodes in NULL
    node* pList = NULL, *pList2 = NULL;

    //Loop that contains insertion elements on the list
    for(int i = 0; i < 1500; i++) 
        //The function recieves another function that generates random numbers
        insertElement(T(getRandom()), &pList);

    //Showing elements in list
    cout << "Every element in list: " << endl;
    traverList(pList);

    //The function recieves the first list and the new one
    //that has the number less than 100
    transferElements(pList, &pList2);

    //Show transfered element into new list
    cout << "Less than 100: " << endl;
    traverList(pList2);
    
    return 0;
}

//Function that generates randomly numbers from 1 to 1500
int getRandom(void) { 
    return rand() % 1500 + 1;
}

template<class e>
void insertElement(e data, node** pList) {
    //Initializing node
    node* n = new node;
    n->info = data;

    //If clause to check the correct insertion of
    //randomly numbers

    //Checking that the new element that will be inserted
    //is greater to the existing one
    if(!*pList || (*pList)->info >= n->info) {
        n->next = *pList;
        *pList = n;
    }
    else {
        node* current = *pList;
        
        //Checking that the new element that will be inserted
        //is smaller than the existing one
        while(current->next && current->next->info < n->info)
            current = current->next;

        //Assigning order into the insertion
        n->next = current->next;
        current->next = n;
    }
}

//Function to transfer elements from list to another one
void transferElements(node* origin, node** dest) {
    if(origin) {
        if(origin->info.data < 100) {
            node* n = new node;
            n->info = origin->info;
            n->next = NULL;

            if(!*dest)
                *dest = n;
            else {
                node* aux = *dest;
                while(aux->next)
                    aux = aux->next;
                
                aux->next = n;
            }
        }
        //Recursive call of the function
        transferElements(origin->next, dest);
    }
}

//Function that travels the elements of the list
void traverList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverList(list->next);
    }
}