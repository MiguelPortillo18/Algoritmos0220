#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

struct queue {
    node* front, *back;
};

void push(int, queue*); 
void traverseQueue(node*);

int main(void) {

    queue q;
    q.front = q.back = NULL;

    for(int i = 0; i < 10; i++)
        push(rand() % 100, &q);
    
    traverseQueue(q);

    return 0;
}

void push(int data, queue* q) {
    node* n = new node;

    n->data = data;
    n->next = NULL;

    if(!q->front) {
        q->front = n;
        q->back = n;
    }
    else {
        q->back->next = n;
        q->back = n;
    }
}

void traverseQueue(node* queue) {
    if(queue) {
        cout << queue->data << " ";
        traverseQueue(queue->next);
    }
    else
        cout << endl;
}