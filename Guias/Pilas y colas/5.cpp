#include <iostream>
using namespace std;

//Node structure
struct node {
    string data;
    node* next;
};

//Function prototypes
void push(string, node**);
void traverseStack(node*);

int main(void) {
    //Initializing node in Main
    node* stk = NULL;
    string aux = "";

    //The program requires the user enters a phrase letter by letter, this phrase will be transformed into a stack that
    //show elements (letter of the phrase) in an inverted order
    cout << "Enter a phrase (Press ENTER to add, Ctrl + D to stop input): "; 

    //While clause that makes the insertion process (inserting phrase) and insertion into the stack
    while(cin >> aux)
        push(aux, &stk);
    
    //Show stack with the inverted phrase
    cout << "Your phrase in the stack: " << endl;
    traverseStack(stk);
    
    return 0;
}

//Function that makes the filling process in a stack
void push(string data, node** stk) {

    //Node assignation logic
    node* n = new node;

    n->data = data;
    n->next = *stk;

    *stk = n;
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