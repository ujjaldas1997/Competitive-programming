#include <iostream>
#include <vector>
using namespace std;

// A Bianry Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
    Node *temp = new Node;
    temp->data = k;
    temp->left = temp->right = NULL;
    return temp;
}

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findNode(Node* root, vector<int>& q, int n){
    if(root == nullptr)
        return 0;
    //q.push(root);
    if(root->data == n){
        q.push_back(root->data);
        return 1;
    }
    if(findNode(root->left, q, n) == 1){
        q.push_back(root->data);
        return 1;
    }
    else if(findNode(root->right, q, n) == 1){
        q.push_back(root->data);
        return 1;
    }
    return 0;
}
int findLCA(Node* root ,int n1 ,int n2 )
{
   //Your code here
    vector<int> q1, q2;
    findNode(root, q1, n1);
    findNode(root, q2, n2);
    int ancestor;
    while(!q1.empty() and !q2.empty()){
        if(q1.back() == q2.back()){
            ancestor = q1.back();
            q1.pop_back();
            q2.pop_back();
        }
        else
            break;
    }
    return ancestor;
}

// Driver program to test above functions
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}

