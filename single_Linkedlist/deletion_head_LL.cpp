#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
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
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
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

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertarr2LL(arr);

    head = deletion(head); // delete head node

    printLL(head); // print remaining linked list

    return 0;
}
