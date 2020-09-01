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
void pop(node** );
node* top(node*);

int main(void) {
    //Initializing node in Main
    node* stack = NULL;
    node* stack2 = NULL;
    
    //Fill stack process
    for(int i = 0; i < 10; i++)
        push(rand() % 100, &stack);

    //Show elements in list
    cout << "Elements in stack: \n" << endl;
    traverseStack(stack);

    for(int i = 0; i < 10; i++){
        node* topInfo = top(stack);

        push(topInfo->data, &stack2);

        pop(&stack);

        topInfo = topInfo->next;
    }

    cout << endl << "Elements in stack: \n" << endl;
    traverseStack(stack2);

    return 0;
}

//Function that makes the filling process in a stack
void push(int data, node** stack) {

    //Node assignation logic

    node* n = new node;
    n->data = data;

    n->next = *stack;

    *stack = n;
}

//Function that goes through the elements of the stack and shows them
void traverseStack(node* stack) {
    if(stack) {
        cout << stack->data << " ";
        traverseStack(stack->next);
    }
    else 
        cout << endl;
}

//Delete first position in stack
void pop(node** stk) {
    node* aux = *stk;
    *stk = (*stk)->next;

    delete aux;
}

node* top(node* s){
    node* r  = new node;
    r->data = s->data;
    s->next = NULL;

    return r;
}

