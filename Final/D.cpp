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
    int count(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + count(node->left) + count(node->right);
    }
    void print(int n){
        for(int i = 0;i<=n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int height(Node* node, int& ans)
    {
        if (node == NULL)
            return 0;
        int left = height(node->left, ans);
        int right = height(node->right, ans);
        ans = max(ans, 1 + left + right);
        return max(left, right)+1;
    }
};

long long tmp;
int main() {
    BST *bst = new BST();
    long long n;
    cin >> n;
    for(int i =0;i<n;i++) {
        long long x;
        cin >> x;
        bst->root = bst->insert(bst->root, x);
    }
    int ans = -1;
    bst->height(bst->root, ans);
    cout << ans;
    return 0;
}