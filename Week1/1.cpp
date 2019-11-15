#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack{
    public:
    Node *top;
    int sz;
    
    Stack() {
        top = NULL;
        sz = 0;
    }

    void push(int data){
        Node *node = new Node(data);
        node->next = this->top;
        top = node;
        sz++;
    }

    bool empty() {
        return (sz == 0);
    }

    void pop() {
        if (!empty()) {
            top = top->next;
            sz--;
        }
    }

    int back() {
        return top->data;
    }

    //int size() {
    //  return sz;
    // }
};

int main() {
    Stack *st = new Stack();
    st->push(4);
    st->push(5);
    st->push(1);
    st->pop();
    cout<<st->back() << endl;
    st->push(10);
    cout << st->back() << endl;
    st->pop();
    st->pop();
    cout << st->back() << endl;
    return 0;
}