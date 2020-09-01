#include <iostream>
#include <time.h>
using namespace std;

//Structure of information contained in nodes
struct nodeData {
    int data;

    //Constructors of struct
    nodeData () {}
    nodeData(int _data) : data(_data) {}
};
typedef nodeData T;

//Node structure
struct node {
    T info;
    node* next;
};

//Prototype functions
void traverseList(node*);
void pushBack(T, node**);
int listSize(node*);

int main(void) {
    //Initializing seed to generate random numbers
    srand(time(NULL));

    //Initializing node
    node* pList = NULL;

    //Loop that fills list with random numbers using a function
    for(int i = 0; i < 20; i++)
        pushBack(T(rand() % 100), &pList);

    //Show results
    cout << "List elements: " << endl;

    traverseList(pList);

    //Show number of nodes in list
    cout << "Number of nodes in list: " << listSize(pList) << endl;

    return 0;
}

//Function that travels through elements in list
void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}

//Function incharge of insert and fill the list
void pushBack(T info, node** list) {
    //Node assigning logic
    node* n = new node;
    n->info = info;
    n->next = NULL;

    //Checking if list exists
    if(!*list)
        *list = n;
    else {

        //data insertion logic
        node* aux = *list;

        while(aux->next)
            aux = aux->next;

        aux->next = n;
    }
}

//Int function that returns number of nodes in a list
int listSize(node* list) {
    if(!list)
        return 0;
    else{
        return listSize(list->next) + 1;
    }
}