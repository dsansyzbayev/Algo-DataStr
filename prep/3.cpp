#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    int size;
    Node *left;
    Node *right;
    
    Node(int data){
        this->data = data;
        this->size = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insertNode(Node *&root, int data){
        if(root == nullptr){
            root = new Node(data);
            return;
        }
        if(data <= root->data){
            insertNode(root->left,data);
        }else{
            insertNode(root->right,data);
        }
}

Node* invertTree(Node *root){
    if(root == nullptr) return nullptr;
    Node *right = invertTree(root->right);
    Node *left = invertTree(root->left);
    root->left = right;
    root->right = left;
    return root;
}

void Print(Node * root) {
	if (root == NULL) return;
	Print(root -> left);
	printf("%d\n", root ->data);
	Print(root -> right);
}

int main(){
    int n,k;
    cin >> n;
    Node *root = nullptr;

    for(int i = 0; i < n; i++){
        cin >> k;
        insertNode(root,k);
    }
    Node *inTree = invertTree(root);
    Print(root);
}