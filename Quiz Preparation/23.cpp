#include <iostream>

using namespace std;

template <typename T>

class Node{
    public:
    T data;
    Node *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class Stack{
    public:
    int sz;
    Node <T> *top;

    Stack(){
        sz = 0;
        top = NULL;
    }

    void push(T data){
        Node <T> *node = new Node<T>(data);
        node->next = this->top;
        top = node;
        sz++;
    }

    void pop(){
        if(!empty()){
            top = top->next;
            sz--;
        }
    }

    bool empty(){
        return (sz == 0);
    }

    int size(){
        return sz;
    }
    
    T getTop(){
        return top->data;
    }
};

int main(){
    Stack <int> *stack = new Stack<int>();

    stack->push(5);
    cout << stack->getTop() << endl;
    stack->push(4);
    stack->push(1);
    stack->pop();
    cout<<stack->getTop() << endl;
    cout<<stack->size();
}