#include <iostream>
#include <time.h>
//Contains information about node structure and functions thaht insert
//elements into a list
#include "LinkedList.h"
using namespace std;

//Function prototypes
void traverseList(node*);
node* insertionSort(node*);

int main(void) {
    //Initializing seed to generate random numbers
    srand(time(NULL));
    //Initializing node
    node* list = NULL;

    // Assuming 50 elements per list
    for(int i = 0; i < 50; i++)
        pushBack(T(rand() % 1000), &list);

    //Calling insertionSort function
    list = insertionSort(list);
    //Show the result of the sorted list
    traverseList(list);

    return 0;
}

//Insertion sort Algorithm code
node* insertionSort(node* list) {
    //Checking if list is empty or not
    if (!list || !list->next)
        return list;

    node* aux = NULL;

    //While clause where happens the elements sorting
    while (list != NULL) {
        node* current = list;
        list = list->next;
        //Sorting elements using the current node of the list
        if (aux == NULL || current->info < aux->info) {
            current->next = aux;
            aux = current;
        } 
        else {
            node* aux2 = aux;
            //While clause that sort the elements if the list is empty
            while (aux2 != NULL) {
                if (aux2->next == NULL || current->info < aux2->next->info) {
                    current->next = aux2->next;
                    aux2->next = current;
                    break;
                }
                aux2 = aux2->next;
            }
        }
    }

    return aux;
}

//Function that travels the elements of a list
void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}