#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};

struct Node_info{
    Node* node;
    int maxm, minm;
};
Node_info make_node(int data, int maxm, int minm){
    Node_info temp;
    temp.node = new Node;
    temp.node->data = data;
    temp.node->left = nullptr;
    temp.node->right = nullptr;
    temp.maxm = maxm;
    temp.minm = minm;
    return temp;
}
Node* constructBst(int arr[], int n)
{
    if(n==0)return NULL;
    // Code here
    Node* root;
    int current = 0;
    queue<Node_info> level({make_node(arr[current++], INT_MAX, INT_MIN)});
    root = level.front().node;
    while(current < n){
        queue<int> value;
        while((current < n) and (value.empty() or value.back() < arr[current]))
            value.push(arr[current++]);
        queue<Node_info> nxt_lvl;
        while(!value.empty()){
            while(!level.empty()){
                Node_info temp = level.front();
                level.pop();
                Node* ntmp = temp.node;
                if(!value.empty() and (value.front() > temp.minm and value.front() < temp.node->data)){
                    nxt_lvl.push(make_node(value.front(), temp.node->data, temp.minm));
                    value.pop();
                    ntmp->left = nxt_lvl.back().node;
                }
                if(!value.empty() and (value.front() > temp.node->data and value.front() < temp.maxm)){
                    nxt_lvl.push(make_node(value.front(), temp.maxm, temp.node->data));
                    value.pop();
                    ntmp->right = nxt_lvl.back().node;
                }
            }
            level = nxt_lvl;
            nxt_lvl = queue<Node_info>();
        }
    }
	return root;
}
void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}
int main(){
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    Node* root = constructBst(arr, 9);
    inorder(root);
    return 0;
}

