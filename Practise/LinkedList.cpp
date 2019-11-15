#include <iostream>

using namespace std;

template <typename T>

class Node{
    public:
    T data;
    Node <T> *next, *prev;

    Node(T data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template <typename T>

class LinkedList{
    public:
    int sz;
    Node <T> *head,*tail;

    LinkedList(){
        sz = 0;
        head = NULL;
        tail = NULL;
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        }
    }

    void pop_front(){
        if(head != NULL){
            head = head->next;
            head->prev = NULL;
        }
        sz--;
    }

    void push_back(T data){
        Node <T> *node = new Node <T>(data);
        if(tail == NULL){
            tail = node;
            head = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void push_front(T data){
        Node <T> *node = new Node<T>(data);
        if(head == NULL){
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }

    void delete_node(Node <T> *node){
        if(node == head){
            pop_front();
        } else if (node == tail) {
            pop_back();
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    void insert_node(Node <T> *node1, Node <T> *node2){
        if(node1 == tail){
            push_back(node2->data);
        } else {
            node1->next->prev = node2;
            node2->next = node1->next;
            node1->next = node2;
            node2->prev = node1;
        }
    }

    Node<T>* search(T data){
        Node <T> *node = head;
        while(node != NULL && node->data != data)
            node = node->next;
        return node;
    }

    void print(){
        Node <T> *node = head;
        while(node != NULL){
            cout<< node->data << "-->";
            node = node->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList <int> *ll = new LinkedList<int>();
    ll->push_back(5);
    ll->push_back(7);
    ll->push_front(20);

    ll->push_front(31);
    ll->push_back(45);
    // 31-->20-->5-->17-->45
    ll->print();
    ll->pop_front();
    ll->pop_back();
    ll->print();
    Node <int> *node = ll->search(5);
    ll->delete_node(node);
    ll->print();

    // LINKED LIST AS QUEUE
    // LinkedList *q = new LinkedList();
    // q->push_back(5);
    // q->head;
    // q->pop_front();

    //LINKED LIST AS STACK
    // LinkedList *st = new LinkedList();
    // st->push_front(6);
    // st->head
    // st->pop_front();

    return 0;
}