#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST{
    public:
    Node *root;
    BST(){
        root = NULL;
    }

    Node *insert(Node *node, int data){
        if (node == NULL){
            node = new Node(data);
            return node;
        }

        if( node->data >= data){
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void inOrder(Node *node){
        if(node == NULL){
            return;
        }

        inOrder(node->left);
        cout<< node->data << " ";
        inOrder(node->right);  
    }

    Node *delete_node(Node *node, int data){
        if (node == NULL){
            return NULL;
        }
    }
};


int main(){

    return 0;
}