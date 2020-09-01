#include <iostream>
#include <time.h>
using namespace std;

//Struct that has required information in nodes
struct nodeData {
    int num;

    //Initializing constructors from struct
    nodeData() {}
    nodeData(int _num) : num(_num) {}
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
int listSize(node*);
int sumatory(node *);

int main(void) {
    //Initializing nodes
    node* list = NULL, *newList = NULL;

    int average = 0;

    //Filling list process
    for(int i = 0; i < 50; i++)
        pushBack(T(rand() % 1000), &list);

    //Show elements in list
    cout << "Elements in list: \n" << endl;
    traverseList(list);

    //Variable that contains the value of the average number containded in list, this is calculated using two functions
    average = sumatory(list) / listSize(list);

    cout << endl << "Average in list: " << average << endl;

    //Filling process in the new list, with the elements that are greater than the average
    while(list) {
        if(list->info.num > average)
            pushBack(T(list->info.num), &newList);

        list = list->next;
    }

    //Show elements in new list
    cout << endl << "Elements in new list greater than average: \n" << endl;
    traverseList(newList);

    return 0;
}

//Function that goes through the elements in the list and show them
void traverseList(node* list){
    if(list){
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

//Function that return the total number of elements in the list
int listSize(node* list) {
    if(!list)
        return 0;
    else 
        return listSize(list->next) + 1;
}

//Int function that the returns the sumatory of elements in list
int sumatory(node * list) {
    int sum = 0;

    while(list) {
        sum = sum + list->info.num;

        list = list->next;
    }

    return sum;
}