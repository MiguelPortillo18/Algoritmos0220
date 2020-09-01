#include <iostream>
#include <time.h>
using namespace std;

//Struct that has required information in nodes
struct nodeData {
    int num;

    //Initializing constructors from struct
    nodeData() {}
    nodeData(int _num) : num(_num) {}

    //Sobrecarga del operador == (Para utilizarlos de forma mas sencilla en la comparacion de nodos en la lista)
    bool operator==(const nodeData& rhs) {
        return this->num == rhs.num;
    }
}; 
typedef nodeData T;

//Node structure
struct node {
    T info;
    node* next;
};

//Function prototypes
void traverseList(node*);
void pushBack(T, node**);
void remove(node**);

int main(void) {
    //Initializing nodes
    node* list = NULL, *aux = NULL;

    //Filling list process
    for(int i = 0; i < 15; i++)
        pushBack(T(rand() % 100), &list);
    
    //Show elements in list
    cout << "Elements in list: " << endl;
    traverseList(list);
    
    //Calling function that removes an specific node in the list
    remove(&list);

    //Show new result
    cout << endl << "Elements in list: " << endl;
    traverseList(list);
    
    return 0;
}

//Function that goes through the elements in the list and show them
void traverseList(node* list) {
    if(list) {
        cout << list->info.num << endl; 
        
        traverseList(list->next);
    }
}

//Function in charge of insert elements in list (fill process)
void pushBack(T info, node** list) {
    //Node assignation logic
    node* n = new node; 
    n->info = info;
    n->next = NULL;

    //Checking if list exists
    if(!*list)
        *list = n;
    else {
        //Insertion logic
        node* aux = *list;

        while(aux->next)
            aux = aux->next;

        aux->next = n;
    }
}

//Recursive function in charge of remove an specific node in a list
void remove(node** list) {
    /*
        if(list) -> ends with NULL
        if(list->next) -> ends at last position
        if(list->next->next) -> ends at one before last position
    */

    if((*list)->next->next) {
        remove(&(*list)->next);
    }
    else
        *list = (*list)->next;
}


