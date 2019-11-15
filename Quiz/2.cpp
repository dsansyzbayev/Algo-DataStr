#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next, *prev;

    Node(int _val) {
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
};

struct LinkedList {
public:
    Node *head, *tail;
    int sz;

    LinkedList() {
        sz = -1;
        head = tail = nullptr;
    }

    int cnt(int x) {
    }

    int getNth(int n) {
        while(sz != n){
            if(head != nullptr){
                deleteFirst();
            }
        }
        return head->val;
    }

    void insertLast(int x) {
        auto node = new Node(x);
        if(tail == nullptr){
            head = node;
            tail = node;
            return;
        } else {
            tail->next = node;
            node->prev = head->next;
            tail = node; 
        }
        sz++;
    }

    void insertFirst(int x) {
        auto node = new Node(x);
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        } else {
            head -> prev = node;
            node -> next = head;
            head = node;
        }
        sz++;
    }

    void deleteFirst() {
        head = head -> next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        sz--;
    }

    void deleteLast() {
        tail = tail -> prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        sz--;
    }

    void del(int x) {
        auto cur = head;
        while (cur && cur -> val != x) {
            cur = cur -> next;
        }
        if (!cur) return;
        if (cur == head) deleteFirst();
        else
        if (cur == tail) deleteLast();
        else {
            cur -> next -> prev = cur -> prev;
            cur -> prev -> next = cur -> next;
        }
    }

    void print() {
        auto cur = head;
        while (cur) {
            if (cur != head) cout << " ";
            cout << (cur -> val);
            cur = cur -> next;
        }
        cout << "\n";
    }

    bool empty(){
        return (sz == 0);
    }
};

int main() {
    int n, x;
    string s;
    auto linkedList = new LinkedList();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "insertFirst") {
            cin >> x;
            linkedList -> insertFirst(x);
        }
        if (s == "delete") {
            cin >> x;
            linkedList -> del(x);
        }
        if (s == "deleteFirst") {
            linkedList -> deleteFirst();
        }
        if (s == "deleteLast") {
            linkedList -> deleteLast();
        }

        if (s == "insertLast") {
            cin >> x;
            linkedList -> insertLast(x);
        }

        if (s == "cnt") {
            cin >> x;
            cout << linkedList -> cnt(x) << "\n";
        }

        if (s == "getNth") {
            cin >> x;
            cout << linkedList -> getNth(x) << "\n";
        }
    }
    linkedList -> print();
}

