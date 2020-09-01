#include <iostream>
using namespace std;

//Node structure
struct node {
    int data; 
    node* next;
};

//Function prototypes
void push(int, node**);
void traverseStack(node*);

int main(void) {
    //Initializing node in Main
    node* stk = NULL;

    int n = 0;

    //the program requires a int number (preference: large int)
    cout << "Insert number: "; cin >> n; cout << endl;

    //Process that makes the division of each digit of the entire into a unique element that is going to be inserted in a stack
    while(n > 0) {
        push(n % 10, &stk);

        n /= 10;
    }

    //Show the result of the transformation from a Int number into a stack with its digits as elements
    cout << "List elements: " << endl;
    traverseStack(stk);

    return 0;
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

//Function that makes the filling process in a stack
void push(int data, node** stk) {

    //Node assignation logic

    node* n = new node;
    n->data = data;

    n->next = *stk;
    *stk = n;
}