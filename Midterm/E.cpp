#include <bits/stdc++.h>

using namespace std;

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
    int a[1111];
    
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
    void child(Node *node) {
        if (node == NULL)
            return;
        child(node->left);
        if (node->left == NULL and node->right == NULL)
            cout << node->data << '\n';
        child(node->right);
    }
    void dd(){
        for(int i =0;i<1111;i++){
            a[i]=0;
        }  
    }
    void forks(Node *node, uint32_t &tmp) {
        if (node == NULL)
            return;
        forks(node->left, tmp);
        if(node->left != NULL and node->right != NULL)
        {
            a[0]++;
            tmp++;
            if(min(depthright(node),depthleft(node))>2)
            {
                int j = min(depthright(node),depthleft(node))-1;
                while(j>1){
                    a[j-1]++;
                    j--;
                }
                // a[min(depthright(node),depthleft(node))-2]++;
            }
            // cout << node->data << " " << depthright(node) << " " << depthleft(node) << "\n";
        }
        forks(node->right, tmp);
    }

    int count(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + count(node->left) + count(node->right);
    }

    int depthleft(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + depthleft(node->left);
    }
    int depthright(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + depthright(node->right);
    }
    void print(int n){
        for(int i = 0;i<=n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

uint32_t tmp;
int main() {
    BST *bst = new BST();
    uint32_t n;
   
    cin >> n;
    int m = n;
    while (n != 0) {
        uint32_t x;
        cin >> x;
        bst->root = bst->insert(bst->root, x);
        n--;
    }
    bst->dd();
    bst->forks(bst->root, tmp);
    // cout << tmp << endl; 
    bst->print(m-2);
    return 0;
}