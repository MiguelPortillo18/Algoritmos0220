#include <iostream>
#include <string>
#include <time.h>
using namespace std;

struct nodeData {
    int data;

    nodeData() {}
    nodeData(int _data): data(_data) {}

    bool operator==(const nodeData& r) {
        return this->data == r.data;
    }

    bool operator<(const nodeData& r) {
        return this->data < r.data;
    }

    bool operator>(const nodeData& r) {
        return this->data > r.data;
    }

    bool operator<=(const nodeData& r) {
        return this->data <= r.data;
    }

    bool operator>=(const nodeData& r) {
        return this->data >= r.data;
    }

    friend ostream& operator<<(ostream& os, const nodeData& n) {
        os << (to_string(n.data));
        return os;
    }
};
typedef nodeData T;

struct node {
    T info;
    node* next;
};

int size(node*);
node* mergeSort(node*);
void pushBack(T, node**);
void traverseList(node*);
node* merge(node*, node*);

int main(void) {
    srand(time(NULL));
    node* list = NULL;

    for(int i = 0; i < 5; i++)
        pushBack(T(rand() % 1000), &list);

    list = mergeSort(list);
    traverseList(list);
    cout << endl;

    return 0;
}

int size(node* list) {
    if(list)
        return 1 + size(list->next);
    else
        return 0;
}

void pushBack(T info, node** list) {
    node* n = new node;
    n->info = info;
    n->next = NULL;

    if(!*list){
        *list = n;
    }
    else {
        node* aux = *list;

        while(aux->next)
            aux = aux->next;
        
        aux->next = n;
    }
}

void traverseList(node* list) {
    if(list) {
        cout << list->info.data << "\t";
        traverseList(list->next);
    }
}

node* mergeSort(node* list) {
    if(!list || !list->next)
        return list;
    
    int listSize = size(list);
    node* left = NULL, *right = NULL, *aux = list;

    for(int  i = 0; i < listSize; i++) {
        if(i < listSize / 2)
            pushBack(aux->info, &left);
        else
            pushBack(aux->info, &right);

        aux = aux->next;
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

node* merge(node* left, node* right) {
    node* resultList = NULL;

    while(left && right) {
        if(left->info <= right->info) {
            pushBack(left->info, &resultList);
            left = left->next;
        }
        else {
            pushBack(right->info, &resultList);
            right = right->next;
        }
    }

    while(left) {
        pushBack(left->info, &resultList);
        left = left->next;
    }

    while(right) {
        pushBack(right->info, &resultList);
        right = right->next;
    }

    return resultList;
}