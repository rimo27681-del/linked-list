#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
//convert array to doubly linked list
Node* convertarr2DLL(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        prev->next=temp;
        temp->back=prev;
        prev=temp;
    }
    return head;

}
//delete head of doubly linked list
Node* deletehead(Node* head){
    if(head==NULL&& head->next==NULL){
        return head;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}
//delete tail of a doublelinkedlist
Node* deletetail(Node* head){
    if(head == NULL||head->next == NULL) {
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newtail = tail->back;
    newtail->next = nullptr;
    delete tail;
    return head;
}
//remove k-th element in dLL
Node* removeKthelement(Node* head,int k){
       if(head==NULL){
        return NULL;
    }
    int count = 0;
    Node* kNode = head;
    while(kNode!=NULL){
        count++;
        if(count==k){
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;
    
    if(prev==NULL && front == NULL){
        delete kNode;
        return NULL;
    }
    else if (prev==NULL){
        return deletehead(head);
    }
    else if(front == NULL){
        return deletetail(head);
    }
    
    prev->next = front;
    front->back = prev;
    
    kNode->next = NULL;
    kNode->back = NULL;
    
    delete kNode;
    
    return head;
}
Node* insertBeforeHead(Node* head,int val){
    Node* newnode=new Node(val,head,nullptr);
    head->back=newnode;
    return newnode;
}
Node* insertBeforeTail(Node* head,int val){
    if(head == NULL){
        // If list is empty or has only one node, insert before head
        return insertBeforeHead(head, val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
Node* insertBeforekthElement(Node* head,int k,int val){
    if(k==1){
        return insertBeforekthElement(head,k,val);
    }
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k)
        break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
} 

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int>arr={12,8,5,2};
    Node* head=convertarr2DLL(arr);
    // head=deletehead(head);
    // head=deletetail(head);
    // head=removeKthelement(head,4);
    // head=insertBeforeHead(head,10);
    // head=insertBeforeTail(head,22);
    head=insertBeforekthElement(head,2,33);
    printLL(head);
    return 0;   
}