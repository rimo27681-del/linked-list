#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* convertarr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]); // creating head 
    Node* mover = head; // pointer pointing towards head
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // creating new node every time
        mover->next = temp; // pointing mover to temp
        mover = mover->next; // moving mover to the next node
    }
    return head;
}

Node* deletion(Node* head) {
    if (head == NULL&&head->next==NULL) {
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int> arr={30,40,50,60,70};
    Node* head=convertarr2LL(arr);
    printLL(head);
    head=deletion(head);
    printLL(head);
    return 0;
}
