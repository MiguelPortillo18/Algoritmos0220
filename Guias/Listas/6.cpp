#include <time.h>
#include <iostream>
#include <cstdlib>
using namespace std;

//Struct that contains information from nodes
struct nodeData {
    int data;

    //Initializing node constructors
    nodeData() {}
    nodeData(int _data) : data(_data) {}
};
typedef nodeData T;

//Node structure
struct node {
    T info;
    node* next;
};

//Function prototypes
void traverseList(node*);
void pushBack(T,node**);

int main(void) {
    //Initializing seed that generates random numbers
    srand(time(NULL));

    //Initializing nodes with NULL
    node* list = NULL, *oddsList = NULL, *evenList = NULL;

    //List's fill process with random numbers
    for(int i = 0; i < 50; i++)
        pushBack(T(rand() % 100), &list);

    //Lambda function in charge of transfer into a new list only elements with odd numbers
    auto transferOdds = [](node* origin, node** destiny) {
        while(origin) {
            if(origin->info.data % 2 != 0)
                pushBack(origin->info, destiny);

            origin = origin->next;
        }
    };

    //Lambda function in charge of transfer into a new list only elements with even numbers
    auto transferEvens = [](node* origin2, node** destiny2) {
        while(origin2) {
            if(origin2->info.data % 2 == 0)
                pushBack(origin2->info, destiny2);
                
            origin2 = origin2->next;
        }
    };

    //Showing all the results
    cout << "Elements in list: " << endl;
    traverseList(list);

    transferEvens(list, &evenList);
    transferOdds(list, &oddsList);

    cout << endl << "Odd elements in new list: " << endl;
    traverseList(oddsList);
    
    cout << endl << "Even elements in new list: " << endl;
    traverseList(evenList);

    return 0;
}

//Function that travels through elements in list and show them in console
void traverseList(node* list) {
    if(list){
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}

//Function that fills the list
void pushBack(T info, node** list) {
    //Node assigning logic
    node* n = new node;
    n->info = info;
    n->next = NULL;

    //checking if list exists
    if(!*list)
        *list = n;
    else {

        //Insertion logic in list
        node* aux = *list;

        while(aux->next)
            aux = aux->next;
        
        aux->next = n;
    }
}