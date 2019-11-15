#include <iostream>

using namespaces std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }

};

class LinkedList{
    public:
    Node *head;
    Node * tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void push_back(int data){
        Node *node = new Node(data);
        if(tail == NULL){
            tail = node;
            head = node;
        } else {
            tail->next = node;
            node->prev = tail;
        }
    }


}