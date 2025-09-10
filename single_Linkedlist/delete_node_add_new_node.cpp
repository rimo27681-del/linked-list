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
//add head
Node* insert_element(Node* head,int k){
    Node* temp=new Node(k,head);
    return temp;
    
}
//add tail
Node* insert_tail(Node* head,int k){
    if(head==NULL){
        return head;
    }
    Node*temp=head;
    Node* prev= new Node(k);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=prev;
    return head;
}
//insert position
Node* insert_position(Node* head,int ele,int k){
    if(head==NULL){
        return head;

    if(k==1){
        return new Node(ele);
    }
    else{
        return head;
    }
    }

    if(k==1){
        return new Node(ele,head);

    }
    int count=0;
    Node* temp=head;
    while (temp!=NULL){
        count++;
        if(count==(k-1)){
            Node* x=new Node(ele,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
    
}
//inseert beefore value
Node* insert_before(Node* head,int ele, int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        return new Node(ele,head);
    }
    Node* temp=head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x=new Node(ele,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
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
    vector<int> arr={12,5,8,7};
    Node* head=convertarr2LL(arr);
    cout<<"before"<<endl;
    printLL(head);
    // head=insert_tail(head,7);
    // cout<<"after"<<endl;
    // printLL(head);
    // head=insert_position(head,100,4);
    // cout<<"insert_position"<<endl;
    head=insert_before(head,100,8);
    cout<<"insert_before"<<endl;
    printLL(head);
    return 0;
}