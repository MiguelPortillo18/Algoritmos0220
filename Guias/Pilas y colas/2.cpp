#include <iostream>
using namespace std;

// Node definition, a T type information field and a pointer to next element
struct node {
    int info;
    node* next;
};

void push(int info, node** stack);
node* top (node* stack);
void pop(node** stack);

int main(void) {
    node* stk = NULL,* stk2 = NULL,* aux = NULL;

    for(int i = 0; i < 10; i++) {
        push(rand() % 12, &stk);
    }

    aux = stk;

    while(aux) {
        cout << aux->info << "  ";
        aux = aux->next;
    }
    cout << endl << endl;

    for(int i = 0; i < 10; i++) {
        push(top(stk)->info, &stk2);
        pop(&stk);
    }
    delete[] stk;
    
    stk = stk2;

    aux = stk;

    while(aux) {
        cout << aux->info << "  ";
        aux = aux->next;
    }
    cout << endl;

    return 0;
}

void push(int info, node** stack) {
    node* n = new node;
    n->info = info;

    n->next = *stack;
    *stack = n;
}

node* top (node* stack) {
    node* n = new node;
    n->info = stack->info;
    n->next = NULL;

    return n;
}

void pop(node** stack) {
    *stack = (*stack)->next;
}