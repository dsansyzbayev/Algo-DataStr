#include <iostream>

using namespace std;

template<typename T>

class Node {
    public:
    T data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
    public:
    Node<T> *top;
    int size;

    Stack(){
        top = NULL;
        size = 0;
    }

    void push(T data){
        Node<T> *node = new Node<T>(data);
        node->next = this->top;
        top = node;
        size++;
    }

    int getSize(){
        return size;
    }

    bool empty() {
        return (size == 0);
    }

    void pop(){
        if(! empty()){
            top= top->next;
            size--;
        }
    }

    T upTop(){
        return top->data;
    }

};

int main(){
    Stack <int> *stack = new Stack<int>();
    
    while(true){
        string s;
        cin >> s;
        if(s == "push"){
            int n;
            cin >> n;
            stack->push(n);
            cout << "ok";
        } else if(s=="pop"){
            if(!stack->empty())
                stack->pop();
            else 
                cout << "error";
        } else if(s=="upTop"){
            if(!stack->empty())
                cout << (stack->upTop());
            else
                cout << "error";
        } else if(s=="size"){
            if(!stack->empty())
                cout << (stack->getSize());
            else
                cout << "0";
        } else if(s=="clear"){
            while(!stack->empty()){
                stack->pop();
            }
            cout << "ok";
        } else if(s=="exit"){
            cout << "bye";
            exit(0);
        }
    }
}