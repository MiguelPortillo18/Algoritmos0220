#include <time.h>
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
using namespace std;

//function prorotype
void traverseList(node*);

int main(void) {
    //initialized nodes, oddslist will be the new list that contains only odd numbers from "list"
    node* list = NULL, *oddsList = NULL;

    //Loop generates the insertions in the list
    for(int i = 0; i < 400; i++) 
        pushBack(T(rand() % 300), &list);

    //Lambda that tranfer the odd numbers from "list" to "oddsList"
    auto transfer = [](node* origin, node** destiny){
        while (origin){
            if(origin->info.data % 2 != 0)
                pushBack(origin->info, destiny);
                
            origin = origin->next;
        }  
    };

    //Show the elements of the list
    cout << "Elements in list: " << endl;
    traverseList(list);

    //Calling function
    transfer(list, &oddsList);

    //Show the elements of the new list
    cout << "Elements in oddsList: " << endl;
    traverseList(oddsList);

    return 0;
}

//Functions that travels the elements of a list
void traverseList(node* list) {
    if(list) {
        cout << list->info.data << endl;
        traverseList(list->next);
    }
}
