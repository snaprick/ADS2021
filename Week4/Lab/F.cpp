#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;
    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << "\n";
        inOrder(node->right);
    }

    Node *findMin(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *delete_node(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data) 
            node->left = delete_node(node->left, data);
        else if (data > node->data)
            node->right = delete_node(node->right, data);
        else {
            if (node->right == NULL && node->left == NULL)
                node = NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *tmp = findMin(node->right);
                node->data = tmp->data;
                node->right = delete_node(node->right, tmp->data);
            }
        }
        return node;
    }
    int maxdepth(Node *node){
        if(node == NULL){
            return 0;
        }
        return max(maxdepth(node->left),maxdepth(node->right))+1;
    }
    int cnt(Node *node)    {
        if(node == NULL){
            return 0;
        }
        return cnt(node->left)+1+cnt(node->right);
    }
    void secondMax(Node *node){
        if (node == NULL)
            return;
        static int cnt;
        secondMax(node->right);
        cnt++;
        if (cnt == 2){
            cout << node->data << endl;
            return;
        }
        secondMax(node->left);
    }
    void branches(Node *node) {
        if (node == NULL)
            return;
        branches(node->left);
        if ((node->left == NULL and node->right != NULL)
            or (node->left != NULL and node->right == NULL))
            cout << node->data << '\n';
        branches(node->right);
    }
    void printLeafs(Node *node){
        if(node == NULL)
            return;
        printLeafs(node->left);
        if(node->left==NULL && node->right==NULL){
            cout << node->data << "\n";
        }
        printLeafs(node->right);
    }
    void fork(Node *node)
    {
        if(node == NULL)
            return;
        fork(node->left);
        if(node->left!=NULL && node->right!=NULL){
            cout << node->data << "\n";
        }
        fork(node->right);
    }
};

int main()
{
    BST *bst = new BST();
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        else 
            bst->root = bst->insert(bst->root, n);
    }
    bst->fork(bst->root);
}