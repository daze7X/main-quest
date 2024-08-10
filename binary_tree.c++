#include <iostream>
using namespace std;

// node
struct Node {
    char label;
    Node *left, *right, *parent;
};

// variabel pointer global
Node *root, *newNode;

// create New Tree
void createNewTree(char label) {
    if (root != NULL)
        cout << "\nTree sudah dibuat" << endl;
    else {
        root = new Node();
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << label << " berhasil dibuat menjadi root." << endl;
    }
}

// insert Left
Node* insertLeft(char label, Node *node) {
    if (root == NULL) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->label << " sudah ada anak kiri!!" << endl;
            return NULL;
        } else {
            newNode = new Node();
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = node;
            node->left = newNode;
            cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
            return newNode;
        }
    }
}

// insert Right
Node* insertRight(char label, Node *node) {
    if (root == NULL) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->label << " sudah ada anak kanan!!" << endl;
            return NULL;
        } else {
            newNode = new Node();
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = node;
            node->right = newNode;
            cout << "\nNode " << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
            return newNode;
        }
    }
}

// Traversal
// preOrder
void preOrder(Node *node) {
    if (node != NULL) {
        cout << node->label << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// inOrder
void inOrder(Node *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->label << ", ";
        inOrder(node->right);
    }
}

// postOrder
void postOrder(Node *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->label << ", ";
    }
}

int main() {
    createNewTree('0');

    Node *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9;

    node1 = insertLeft('1', root);
    node2 = insertRight('2', root);
    node3 = insertLeft('3', node1);
    node4 = insertRight('4', node1);
    node5 = insertLeft('5', node2);
    node6 = insertLeft('6', node4);
    node7 = insertRight('7', node4);
    node8 = insertLeft('8', node6);
    node9 = insertRight('9', node6);

    cout << "\nPreOrder Traversal :" << endl;
    preOrder(root);
    cout << "\n" << endl;

    cout << "InOrder Traversal :" << endl;
    inOrder(root);
    cout << "\n" << endl;

    cout << "PostOrder Traversal :" << endl;
    postOrder(root);
    cout << "\n" << endl;

    return 0;
}
