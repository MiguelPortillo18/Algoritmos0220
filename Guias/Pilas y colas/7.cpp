#include <iostream>
using namespace std;

//Enum that has the process that you can do in a bank
enum operation {RETIRE, DEPOSIT, QUERY, UPDATE, PAYMENT};

//Struct about transactions information 
struct transaction {
    operation op;
    double duration;

    //Initializing constructors
    transaction() {}
    transaction(operation _op, double _duration) : op(_op), duration(_duration) {}
    transaction(const transaction& t) : op(t.op), duration(t.duration) {}
};

//Struct about person information 
struct person {
    string name;
    transaction trans;
    int quantity;

    //Initializing constructors
    person() {}
    person(string _name, transaction _trans, int _quantity) : name(_name), trans(_trans), quantity(_quantity) {}
};
typedef person T;

//Node structure
struct node{
    T info; 
    node* next;
};

//Struct with queue information
struct queue {
    node* front, *back;
};

//Function prototypes
int size(node*);
void push(queue*, T);
double average(queue);

//Constant variables that contains duration in minutes of each transaction type you can do in a bank
const transaction ret(RETIRE, 4);
const transaction dep(RETIRE, 2);
const transaction que(QUERY, 3.5);
const transaction up(UPDATE, 5);
const transaction pay(PAYMENT, 2);

int main(void) {
    //Initialziing node in Main
    queue q;
    q.front = q.back = NULL;

    //Inserting information into the queue
    push(&q, T("Walter", ret, 2));
    push(&q, T("Enmanuel", dep, 3));        
    push(&q, T("Daniela", dep, 2));
    push(&q, T("Miguel", pay, 4));
    push(&q, T("Andrea", up, 1));
    push(&q, T("Xiomara", que, 1));
    push(&q, T("Rafael", ret, 1));

    //Show the result of the average time that people can be in the bank
    cout << "Average waiting time: " << average(q) << " minutes" << endl;

    return 0;
}

//Function that return the number of nodes in the queue
int size(node* q) {
    return q ? 1 + size(q->next) : 0;
}

//Function in charge of fill the queue
void push(queue* q, T info) {

    //Node assignation logic
    node* n = new node;

    n->info = info;

    n->next = NULL;

    //Checking if information will be inserted at the beggining or at the end of the queue
    if(!q->front) {
        q->front = n;
        q->back = n;
    }
    else {
        q->back->next = n;
        q->back = n;
    }
}

//Function that returns the average time that a person can reach while is in the bank
double average(queue q) {
    double aux = 0;

    node* auxPtr = q.front;

    while(auxPtr) {
        aux += (auxPtr->info.trans.duration * auxPtr->info.quantity);
        auxPtr = auxPtr->next;
    }

    return aux / size(q.front);
}