#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

 
Node* insert(Node* head, Node* node, int p){
    if(head == NULL)
        return node;
    Node* pointer = head;
    int cnt = 0;
    while(pointer->next != NULL){
        if(cnt == p){
            node->next = pointer->next;
            pointer->next = node;
            break;
        }
        cnt++;
        pointer = pointer->next;
    }
    return head;
}
 
Node* remove(Node* head, int p){
    Node* temp = head;
    Node* prev = NULL;
    if (temp != NULL && temp->val == p)
    {
        head = temp->next;
        return head;
    }
    else
    {
    while (temp != NULL && temp->val != p)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return head;
    prev->next = temp->next;
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    while (head != NULL)
    {
        if (head->val == p1)
            head->val = p2;
        head = head->next;
    }
    return head;
}
 
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
void print(Node* head){
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        if (temp != NULL)
            temp = temp->next;
    }
    prev->next = head;
    head = head->next;
    prev->next->next = NULL;
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        if (temp != NULL)
            temp = temp->next;
    }
    prev->next = head;
    head = head->next;
    prev->next->next = NULL;
    return head;
}
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}