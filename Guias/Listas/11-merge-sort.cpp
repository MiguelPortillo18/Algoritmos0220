#include <iostream>
#include <time.h>
//Contains information about node structure and functions thaht insert
//elements into a list
#include "LinkedList.h"
using namespace std;

//Function prototypes
int size(node*);
node* mergeSort(node*);
void traverseList(node*);
node* merge(node*, node*);

int main(void) {
    //initializing seed to generate random numbers
    srand(time(NULL));
    //Initializing nodes
    node* list = NULL;

    // Assuming 50 elements per list
    for(int i = 0; i < 5; i++)
        pushBack(T(rand() % 1000), &list);

    //Calling mergesort function
    list = mergeSort(list);
    //Show the result of the sorted list
    traverseList(list);

    return 0;
}

//Function that returns the size of a list
int size(node* list) {
    if(list) {
        return 1 + size(list->next);
    }
    else
        return 0;
}

//List that travel the elements of a list
void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}

//Merge-sort algorithm code
node* mergeSort(node* list) {
    //checking if list is empty or not
    if(!list || !list->next)
        return list;

    int listSize = size(list);    
    //initializing nodes
    //The algorithm indicates that it will be necessary have this nodes
    node* left = NULL,* right = NULL,* aux = list;

    //separating the list in two equal parts
    for(int i = 0; i < listSize; i++) {
        if(i < listSize / 2)
            pushBack(aux->info, &left);
        else
            pushBack(aux->info, &right);

        aux = aux->next;
    }

    //Assigning elements of each list
    left = mergeSort(left);
    right = mergeSort(right);

    //recursive call of the functions that sorts the two already sorted lists
    return merge(left, right);
}

//Function that joins the two sorted lists and make the final result
node* merge(node* left, node* right) {
    node* resultList = NULL;

    //While clause that makes the sort of each mini-list
    //The smaller values will be pushed in order into the left list
    //then the right list will be filled too
    while(left && right) {
        if(left->info <= right->info){
            pushBack(left->info, &resultList);
            left = left->next;
        }
        else {
            pushBack(right->info, &resultList);
            right = right->next;
        }
    }

    //Sorting elements into corresponding list
    while(left) {
        pushBack(left->info, &resultList);
        left = left->next;
    }

    while(right) {
        pushBack(right->info, &resultList);
        right = right->next;
    }

    return resultList;
}