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
int lengthofLL(Node*head){
    int count=0;
    Node*temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}

int main(){
    vector<int>arr={9,8,5,2};
    Node* head=convertarr2LL(arr);
    cout<<lengthofLL(head)<<endl;
 

    return 0;
}