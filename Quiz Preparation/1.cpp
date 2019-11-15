#include <iostream>

using namespace std;


template<typename T>

class Node{
	public:
	T data;
	Node *prev;
	Node *next;
	Node(T data){
		this -> data = data;
	}
};


template<typename T>

class Queue{
	public:
	Node<T> *head, *tail;
	int sz;
	Queue(){
		head = NULL;
		tail = NULL;
		sz = 0;
	}


	void push_back(T data){
		Node<T> *node = new Node<T>(data);
		if(head==NULL){
			head =node;
			tail = node;
		}

		else{
			tail->next = node;
			tail = node;
		}
		sz++;
	}

	void pop_front(){
		head = head->next;
		sz--;
	}

	int size(){
		return sz;
	}

	bool empty(){
		return sz==0;
	}

	T first(){
		return head->data;
	}

	T last(){
		return tail->data;
	}
};


int main(){

	Queue<int> *queue = new Queue<int>();

	while(true){
		string s;
		cin >> s;
		if(s=="push_back"){
			int data;
			cin >> data;
			queue->push_back(data);
			cout << "ok";
		}

		else if(s=="pop_front"){
			queue->pop_front();
			cout << "ok";
		}

		else if(s=="size"){
			cout << queue -> size();
		}

		else if(s=="first"){
			cout << queue->first();
		}

		else if(s=="last"){
			cout << queue ->last();
		}
	}

	return 0;
}