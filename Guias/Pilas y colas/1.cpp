#include <iostream>
using namespace std;

//Node structure
struct node {
    int data;
    node* next;
};

//Function prototypes
void push(int, node**);
void replace(int, int, node**);
void traverseStack(node*);

int main(void) {
    //Initializing node in Main
    node* stk = NULL;

    //Filling stack process
    for(int i = 0; i < 10; i++)
        push(rand() % 5, &stk);

    //Calling function that shows the elements in the stack
    traverseStack(stk);

    //Calling function that recieves a new number and this replaces and old one that is specified in the function too
    replace(9, 2, &stk);

    //Show new results
    traverseStack(stk);

    return 0;
}

//Function that makes the filling process in a stack
void push(int data, node** stk) {

    //Node assignation logic

    node* n = new node;
    
    n->data = data;
    n->next = *stk;

    *stk = n;
}

//function that recieves a new number and this replaces and old one that is specified in the function too
void replace(int ne, int old, node** stk) {
    if(*stk) {
        if((*stk)->data == old)
            (*stk)->data = ne;

        //Recursive call of the function
        replace(ne, old, &(*stk)->next);
    }
}

//Function that goes through the elements of the stack and shows them
void traverseStack(node* stk) {
    if(stk) {
        cout << stk->data << " ";

        traverseStack(stk->next);
    }
    else
        cout << endl;
}