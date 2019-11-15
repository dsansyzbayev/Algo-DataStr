#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree{
    public:
    Node *root;
    Tree(){
        root = NULL;
    }

    Node *insert_node(Node *node, int data){
        if( node == NULL){
            Node *node = new Node(data);
            return node;
        }

        if(data <= node->data){
            node->left = insert_node(node->left,data);
        } else {
            node->right = insert_node(node->right, data);
        }

        return node;
    }

    bool ifNodeExist(struct Node *node, int key){
        if(node == NULL)
            return false;

        if(node->data == key || node->data == key+1 || node->data == key-1)
            return true;

        bool res1 = ifNodeExist(node->left, key);

        bool res2 = ifNodeExist(node->left, key);

        return res1 || res2;
    }
};

int main(){
    Tree *t = new Tree();
}