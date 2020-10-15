#include <iostream>
using namespace std;

struct number {
    int num;

    number() {}
    number(int _num) : num(_num) {}

    bool operator<(const number& n) {
        return this->num < n.num;
    }

    bool operator>(const number& n) {
        return this->num > n.num;
    }

    bool operator==(const number& n) {
        return this->num == n.num;
    }

    friend ostream& operator<<(ostream& os, const number& n) {
        os << (n.num);
        return os;
    }
};
typedef number T;

struct node {
    T info;
    node* left, *right;

    node() : left(NULL), right(NULL) {}
    node(T _info) : info(_info), left(NULL), right(NULL) {}
};

void inOrder(node*);
void insertInTree(T, node**);
void sendDataFromArray(int*, int, node**);

int main(void) {
    node* tree = NULL;
    int inOrderArr[] = {10 , 20 , 30 , 100 , 150 , 200 , 300};

    sendDataFromArray(inOrderArr, 7, &tree);

    inOrder(tree);
    cout << endl;
    
    return 0;
}

void sendDataFromArray(int* arr, int size, node** tree) {
    for(int i = 0; i < size; i++)  
        insertInTree(T(arr[i]), &(*tree));
}

void insertInTree(T info, node** tree) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->info)
            insertInTree(info, &(*tree)->left);
        else
            insertInTree(info, &(*tree)->right);
    }
}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->info << "\t";
        inOrder(tree->right);
    }
}
