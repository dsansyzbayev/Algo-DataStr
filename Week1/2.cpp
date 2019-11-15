#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
    public:
    int sz;
    Node *tail, *head;

    Queue() {
        tail = head = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        tail->next = node;
        tail = node;
        sz++;
    }

    void pop() {
        if( head != NULL) {
            sz--;
            head = head->next;
        }
    }
};

int main () {
    
    return 0;
}