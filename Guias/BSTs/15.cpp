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

    bool operator+(const number& n) {
        return this->num + n.num;
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
void verifyNodes(int, node*);
void insertInTree(T, node**);
void sendDataFromArray(int*, int, node**);

int main(void) {
    node* tree = NULL;
    int n = 0;

    insertInTree(T(25), &tree);
    insertInTree(T(35), &tree);
    insertInTree(T(15), &tree);
    insertInTree(T(10), &tree);
    insertInTree(T(1), &tree);
    insertInTree(T(26), &tree);
    insertInTree(T(17), &tree);
    insertInTree(T(13), &tree);
    insertInTree(T(18), &tree);
    insertInTree(T(5), &tree);

    inOrder(tree);
    cout << endl;

    verifyNodes(35,tree);
    
    return 0;
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

void verifyNodes(int n, node* tree) {
    if(tree) {
        verifyNodes(n, tree->left);

        if((tree->info + tree->info) == n)
            cout << tree->info << "\t";

        verifyNodes(n, tree->right);
    }
}