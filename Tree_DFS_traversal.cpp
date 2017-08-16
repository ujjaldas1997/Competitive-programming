#include<iostream>
#include<stack>
#include "tree.h"
using namespace std;
void preorder_traversal_with_recursion(node* const tree){
	if(tree == nullptr) return;
	cout << tree->data << " ";
	preorder_traversal_with_recursion(tree->left);
	preorder_traversal_with_recursion(tree->right);
}
void postorder_traversal_with_recursion(node* const tree){
	if(tree == nullptr) return;
	postorder_traversal_with_recursion(tree->left);
	postorder_traversal_with_recursion(tree->right);
	cout << tree->data << " ";
}
void inorder_traversal_with_recursion(node* const tree){
	if(tree == nullptr) return;
	inorder_traversal_with_recursion(tree->left);
	cout << tree->data << " ";
	inorder_traversal_with_recursion(tree->right);
}
void preorder_traversal_without_recursion(node* const tree){
	cout << "Iterative method preorder traversal : ";
	if(tree == nullptr) return;
	stack<node*> box;
	box.push(tree);
	node *temp;
	while(!box.empty()){
		temp = box.top();
		box.pop();
		cout << temp->data << " ";
		if(temp->right != nullptr)
			box.push(temp->right);
		if(temp->left != nullptr)
			box.push(temp->left);
	}
	cout << endl;
	return;
}
void postorder_traversal_without_recursion_two_stack_method(node* const tree){
	cout << "Iterative method post order traversal 2 stack method : ";
	stack<node*> box1, box2;
	box1.push(tree);
	node* temp;
	while(!box1.empty()){
		temp = box1.top();
		box1.pop();
		box2.push(temp);
		if(temp->left != nullptr)
			box1.push(temp->left);
		if(temp->right != nullptr)
			box1.push(temp->right);
	}
	while(!box2.empty()){
		temp = box2.top();
		box2.pop();
		cout << temp->data << " ";
	}
	cout << endl;
	return;
}
int main()
{
	node* tree = new node;
	construct(tree);
	cout << "Preorder traversal : ";
	preorder_traversal_with_recursion(tree);
	cout << endl << "Postorder traversal : ";
	postorder_traversal_with_recursion(tree);
	cout << endl << "Inorder traversal : ";
	inorder_traversal_with_recursion(tree);
	cout << endl;
	preorder_traversal_without_recursion(tree);
	postorder_traversal_without_recursion_two_stack_method(tree);
	return 0;
}
