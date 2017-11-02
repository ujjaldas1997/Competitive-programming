#include <bits/stdc++.h>
using namespace std;


// Structure for a tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Iterative Function to print all ancestors of a given key
void printAncestors(struct Node *root, int key)
{
    stack<Node*> v;
    while(true){
        while(root and root->data != key){
            v.push(root);
            root = root->left;
        }
        if(v.empty() or (root and root->data == key))
            break;
        root = v.top();
        if(!root->right){
            v.pop();
            while(!v.empty() and v.top()->right == root){
                root = v.top();
                v.pop();
            }
        }
        root = (v.empty()) ? nullptr : v.top()->right;
    }
    while(!v.empty()){
        cout << v.top()->data << " ";
        v.pop();
    }
    cout << endl;
}

// Driver program to test above functions
int main()
{
    // Let us construct a binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->right->right->left = newNode(10);

    cout<<"Following are all keys and their ancestors"<<endl;
    for (int key = 10; key <= 10; key++)
    {
        cout<<key<<":"<<" ";
        printAncestors(root, key);
        cout<<endl;
    }

    return 0;
}

