#include <iostream>

using namespace std;

template <typename T>

class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class Queue{
    public:
    int sz;
    Node <T> *head, *tail;

    Queue(){
        sz = 0;
        head = NULL;
        tail = NULL;
    }

    void push(T data){
        Node <T> *node = new Node<T>(data);
        if(head == NULL){
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        sz++;
    }

    void pop(){
        if(head != NULL){
            head = head->next;
        }
        sz--;
    }

    T front(){
        if(head == NULL)
            return 0;
        return head->data;
    }

    bool empty(){
        return (sz == 0);
    }

    int size(){
        return sz;
    }
};

int main(){

    Queue <int> *q = new Queue <int>();

    q->push(5);
    q->push(9);
    q->push(7);
    q->pop();
    cout << q->front() << endl;
    cout << q->size();



    return 0;
}