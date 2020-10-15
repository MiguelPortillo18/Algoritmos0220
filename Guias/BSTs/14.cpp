#include <iostream>
using namespace std;

struct number {
    int data;

    number() {}
    number(int _data) : data(_data) {}

    bool operator<(const number& r){
        return this->data < r.data;
    }

    bool operator>(const number& r){
        return this->data < r.data;
    }
    
    bool operator<=(const number& r){
        return this->data <= r.data;
    }

    bool operator>=(const number& r){
        return this->data >= r.data;
    }

    bool operator==(const number& r) {
        return this->data == r.data;
    }

    friend ostream& operator<<(ostream& os, const number& n) {
        os << (n.data);
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
T inOrderSuccesor(node*);
void removeData(T, node**) ;
void insertInTree(T, node**);
void removeDataFromRange(int, int, node**);

int main(void) {
    node* tree = NULL;
    int a, b = 0;

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

    removeDataFromRange(15,30,&tree); 

    inOrder(tree);
    cout << endl;

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

T inOrderSuccesor(node* rightTree) {
    node* aux = rightTree;

    while(aux->left != NULL)
        aux = aux->left;

    return aux->info;
}

void removeData(T e, node** tree) {
    if(*tree) {
        if(e < (*tree)->info) {
            removeData(e, &(*tree)->left);
        }
        else if (e > (*tree)->info) {
            removeData(e, &(*tree)->right);
        }
        else {
            // If node to be deleted is leaf
            if(!(*tree)->left && !(*tree)->right) {
                node* auxDelete = *tree;
                *tree = NULL;
                delete auxDelete;
            }
            // If tree only has right side
            else if(!(*tree)->left && (*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->right;
                delete root;
            }
            // If tree only has left side
            else if((*tree)->left && !(*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->left;
                delete root;
            }
            // If tree is root
            else {
                // Find inorder succesor
                (*tree)->info = inOrderSuccesor((*tree)->right);
                // Delete inorder succesor
                removeData((*tree)->info, &(*tree)->right);
            }
        }
    }
}

void removeDataFromRange(int a, int b, node** tree) {
    if(tree) {
        removeDataFromRange(a, b, &(*tree)->left);

        if((*tree)->info >= a && (*tree)->info <= b)
            removeData(T((*tree)->info), tree);
            
        removeDataFromRange(a, b, &(*tree)->right);
    }
}
