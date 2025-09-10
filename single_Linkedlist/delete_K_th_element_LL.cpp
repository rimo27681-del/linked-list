#include<bits/stdc++.h>
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
Node* convertarr2LL(vector<int>& arr){
    Node* head= new Node(arr[0]); //creating head 
    Node* mover=head; //pointer pointing towards head
    for (int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]); //creating new node every time
        mover->next=temp; //pointing mover to temp
        mover=mover->next; //moving mover to the next node
    }
    return head;
}
Node* deleteKthElement(Node* head,int k){
    if (head == NULL) return NULL;
        if (head->data== k) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* prev=NULL;
    Node* temp=head;
    while(temp->next!=NULL){
        count++;
        if(temp->data==k){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        //if k is another nober which not available in the linkedlist then its code run;
        prev=temp;
        temp=temp->next;
    }
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
    vector<int> arr={12,5,8,7};
    Node* head=convertarr2LL(arr);
    cout<<"before"<<endl;
    printLL(head);
    head=deleteKthElement(head,7);
    cout<<"after"<<endl;
    printLL(head);
    return 0;
}