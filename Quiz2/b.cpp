#include <bits/stdc++.h>

using namespace std;
int cnt = 0;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	} else if (root->data >= data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		}
        else {
			root->left = add(root->left, data);
		}
	} else if (root->data <= data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		}
        else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

int getCnt(Node * root,int data){
    
    return cnt;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int main(){
    Node *root = NULL;

    int q,n;
    int cnt = 0;

    cin >> q;
    string s;
    for(int i = 0; i < q; ++i){
        cin>>s;

        if(s == "insert"){
            cin >> n;
            add(root,n);
        } 
        else if(s == "cnt"){
            cin >> n;
            cout << cnt;
        }
        else if(s == "delete"){
            cin >> n;
            deleteNode(root,n);
        }
    }
}