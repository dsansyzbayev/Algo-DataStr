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

        if(data <= node->data ){
            node->left = insert_node(node->left, data);
        } else {
            node->right = insert_node(node->right, data);
        }

        return node;
    }

    bool ifNodeExists(struct Node* node, int key) 
    { 
    if (node == NULL) 
        return false; 
  
    if (node->data == key || node->data == key+1 || node->data == key-1) 
        return true; 
  
    bool res1 = ifNodeExists(node->left, key); 
  
    bool res2 = ifNodeExists(node->right, key); 
  
    return res1 || res2; 
    }
};

int main(){
    Tree *t = new Tree();
    Node *node  = t->insert_node(NULL, 50);
    t->root = node;

    t->root = t->insert_node(t->root, 30);
    t->root = t->insert_node(t->root, 20);
    t->root = t->insert_node(t->root, 40);
    t->root = t->insert_node(t->root, 70);
    t->root = t->insert_node(t->root, 60);
    t->root = t->insert_node(t->root, 80);

    int key = 79;

    if (t->ifNodeExists(t->root, key)) 
        cout << "YES"; 
    else
        cout << "NO"; 
    return 0;
}