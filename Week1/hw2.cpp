#include <iostream>
#include <queue>

using namespace std;

template<typename T>

class Node{
	public:
	T data;
	Node *next;
	Node *prev;

	Node(int data){
		this ->data = data;
		next = NULL;
		prev = NULL;
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
		sz= 0;
	}

	int size(){
		return sz;
	}

	bool empty(){
		return sz == 0;
	}

	void push_back(T data){
		Node<T> *node = new Node<T>(data);
		if(head == NULL){
			head = node;
			tail = node;
		}
		else {
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
		sz++;
	}

	void push_front(T data){
		Node<T> *node = new Node<T>(data);
		if(head == NULL){
			tail=node;
			head = node;
		}
		else {
			node->next = head;
			head->prev = node;
			head = node;
		}
		sz++;
	}

	void pop_front(){
		if(head!= NULL){
			head = head->next;
			sz--;
		}  
	}

	void pop_back(){
		if(tail!=NULL){
			tail = tail->prev;
			sz--;
		}
	}

	T last(){
		return tail->data;
	}

	T front(){
		return head->data;
	}
};

int main(){
	Queue<int> *queue = new Queue<int>();

	while(true){
		string s;
		cin >> s;
		if(s=="push_front"){
			int n;
			cin >> n;
			queue->push_front(n);
			cout<< "ok";
		}

		else if(s=="push_back"){
			int n;
			cin >> n;
			queue->push_back(n);
			cout << "ok";
		}

		else if(s=="pop_front"){
			if(queue->size()>0)
				queue->pop_front();
			else 
				cout << "error";
		}

		else if(s=="pop_back"){
			if(queue -> size() >0)
				queue->pop_back();
			else 
				cout << "error";
		}

		else if(s=="front"){
			if(queue->size()>0)
				cout << queue->front();
			else 
				cout << "error";
		}

		else if(s=="last"){
			if(queue->size() >0)
				cout << queue ->last();
			else 
				cout << "error";
		}

		else if(s=="size"){
			cout << queue->size();
		}

		else if(s=="clear"){
			while(!queue->empty()){
				queue->pop_back();
			}
			if(queue->empty()){
				cout << "ok";
			}
		}

		else if(s=="exit"){
			cout << "bye";
			exit(0);
		}

	}


	return 0;
}