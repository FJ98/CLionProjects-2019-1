// Created by felix on 6/25/2019.
#ifndef HILOSCLASE1_TBT_H
#define HILOSCLASE1_TBT_H

static constexpr int  MAX_VALUE = 2000;

struct Node{
    int key;
    Node* left; Node* right;
    bool leftThread; bool rightThread;
    explicit Node() = default;
};

class ThreadedBinaryTree{
private:
    Node* root;
public:
    ThreadedBinaryTree();
    void vaciar();
    bool search(int key);
    void insert(int key);
    void insertConHilos(int key, ThreadedBinaryTree tbt);
    ThreadedBinaryTree testInsertConHilos(int key);
    ThreadedBinaryTree testInsertConHilos2(int key1,int key2);
    void delet(int key);
    void print();
};

ThreadedBinaryTree::ThreadedBinaryTree() {
    root = new Node();
    root->right = root->left = root;
    root->leftThread = true;
    root->key = MAX_VALUE;
}

void ThreadedBinaryTree::vaciar() {
    root = new Node();
    root->right = root->left = root;
    root->leftThread = true;
    root->key = MAX_VALUE;
}

bool ThreadedBinaryTree::search(int key) {
    Node *tmp = root->left;
    for (;;) {
        if (tmp->key < key) {
            if (tmp->rightThread) { return false; }
            tmp = tmp->right;
        }
        else if (tmp->key > key) {
            if (tmp->leftThread) { return false; }
            tmp = tmp->left;
        } else { return true; }
    }
}

void ThreadedBinaryTree::insert(int key) {
    Node *p = root;
    for (;;){
        if (p->key < key){
            if (p->rightThread) { break; }
            p = p->right;
        }
        else if (p->key > key){
            if (p->leftThread) { break; }
            p = p->left;
        }
        else{ return; }
    }
    Node *tmp = new Node();
    tmp->key = key;
    tmp->rightThread = tmp->leftThread = true;
    if (p->key < key) {
        /* insertar al lado derecho */
        tmp->right = p->right;
        tmp->left = p;
        p->right = tmp;
        p->rightThread = false;
    } else {
        tmp->right = p;
        tmp->left = p->left;
        p->left = tmp;
        p->leftThread = false;
    }
}

void ThreadedBinaryTree::insertConHilos(int key, ThreadedBinaryTree tbt) {
    Node *p = tbt.root;
    for (;;){
        if (p->key < key){
            if (p->rightThread) { break; }
            p = p->right;
        }
        else if (p->key > key){
            if (p->leftThread) { break; }
            p = p->left;
        }
        else{ return; }
    }
    Node *tmp = new Node();
    tmp->key = key;
    tmp->rightThread = tmp->leftThread = true;
    if (p->key < key) {
        /* insertar al lado derecho */
        tmp->right = p->right;
        tmp->left = p;
        p->right = tmp;
        p->rightThread = false;
    } else {
        tmp->right = p;
        tmp->left = p->left;
        p->left = tmp;
        p->leftThread = false;
    }
}

ThreadedBinaryTree ThreadedBinaryTree::testInsertConHilos(int key) {
    auto fun = &ThreadedBinaryTree::insertConHilos;
    std::thread t1(fun, this, key, *this);
    t1.join();
    return *this;
}

ThreadedBinaryTree ThreadedBinaryTree::testInsertConHilos2(int key1,int key2) {
    auto fun = &ThreadedBinaryTree::insertConHilos;
    std::thread t1(fun, this, key1, *this);
    std::thread t2(fun, this, key2, *this);
    t1.join(); t2.join();
    return *this;
}

void ThreadedBinaryTree::delet(int key) {

}

void ThreadedBinaryTree::print() {
    Node *tmp = root, *p = nullptr;
    std::cout << "  Arbol =   ";
    for (;;){
        p = tmp;
        tmp = tmp->right;
        if (!p->rightThread) {
            while (!tmp->leftThread) {
                tmp = tmp->left;
            }
        }
        if (tmp == root) { break; }
        std::cout << tmp->key << "   ";
    } std::cout << std::endl;
}

#endif //HILOSCLASE1_TBT_H
