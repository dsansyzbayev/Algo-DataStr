#include <iostream>

using namespace std;

template <typename T>

class Node{
    public:
    T data;
    Node *next;
    Node *prev;

    Node(T data){
        this->data = data;
        next = NULL;
        prev = NULL;   
    }
};

template <typename T>

class Queue{
    public:
    Node <T> *tail, *head;
    int sz;

    Queue() {
        tail = head = NULL;
        sz = 0;
    }

    void push(T data) {
        Node <T>*node = new Node <T> (data);
        if(empty()){
            head = node;
            tail = node;
        } else {
            node->prev = tail;
            node->next = node;
            tail = node;
        }
        sz++;
    }
    void pop() {
        if (head != NULL) {
            sz--;
            head = head->next;
        }
    }

    int front() {
        return head->data;
    }

    bool empty() {
        return sz == 0;
    }
};

int main(){
    Queue<int> *q = new Queue<int>();
    
    q->push(5);
    q->push(7);
    q->push(9);

    q->pop();
    cout << q->front();
}