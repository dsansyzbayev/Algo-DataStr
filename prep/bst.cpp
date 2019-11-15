#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data, height;
    Node *left;
    Node *right;

    Node(int data){
        this->height = 0;
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int getHeight(Node *branch){
    if(branch == nullptr) return 0;
    return branch->height;

}
void addNode(Node *&root, int data){
    if(root == nullptr){
        root = new Node(data);
        return; 
    }
    if(data <= root->data){
        addNode(root->left, data);
    } else {
        addNode(root->right, data);
    }
    root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
}

int main(){
    Node *root = nullptr;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        addNode(root,k);
    }
    int h = root->height+1;
    cout<<h<<endl;
}