#include <iostream>
//Contains information about node structure and functions thaht insert
//elements into a list
#include "LinkedList.h"  
using namespace std;

//Function prototype
char empty(node* list);

int main(void) {
    node* list = NULL;

    //function that inserts elements into a list like a queue
    pushBack(T(3), &list);
    pushBack(T(5), &list);
    pushBack(T(7), &list);
    pushBack(T(9), &list);

    //Lambda function that cheks if list is empty or not
    auto empty = [](node* list) {
        //0 implies emptyness
        return list == NULL ? '0' : '*';
    };

    //Show results
    cout << "Empty: " << empty(list) << endl;

    return 0;
}