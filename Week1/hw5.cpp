#include <iostream>

template<typename T>

class Node{
	public:
	T data;
	Node *next;

	Node(T data){
		this-> data = data;
		next = NULL;
	}
};



template<typename T>
class Stack{
	public:
	Node<T> *top;
	int sz;

	Stack(){
		top = NULL;
		sz = 0;
	}

	int size(){
		return sz;
	}

	bool empty(){
		if (sz==0){
			return true;
		}

		else 
			return false;
	}

	void push(T data){
		Node <T> *node = new Node<T>(data);
		node -> next = top;
		top = node;
		sz++;
	}

	void pop(){
		if(top!=NULL){
			top = top->next;
			sz--;
		}
	}

	T back(){
		return top->data;
	}
};

int main(){
	Stack<int> *stack = new Stack<int>();

	while(true){
		string s;
		cin >> s;

		if(s=="push"){
			int n;
			cin >> n;
			stack->push(n);
			cout << "ok";
		}
		else if(s=="pop"){
			if(!stack->empty()){
				stack->pop();
			}
			else 
				cout << "error";
		}

		else if(s=="size"){
			if(!stack->empty()){
				cout << (stack->size());
			}
			else 
				cout << "error";
		}

		else if(s=="back"){
			cout << (top -> data);
		}
	}


	return 0;
}