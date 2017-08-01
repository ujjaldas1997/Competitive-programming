#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct node{
	int data = 0;
	node* left = nullptr;
	node* right = nullptr;
};
void construct(struct node* &tree)
{
	tree->data = 66;
	tree->left = new node;
	tree->right = new node;
	tree->left->left = new node;
	tree->left->left->left = new node;
	tree->left->left->right = new node;
	tree->left->left->left->left = new node;
	tree->left->left->left->right = new node;
	tree->left->left->left->right->right = new node;
	tree->right->right = new node;
	tree->right->left = new node;
	tree->right->left->left = new node;
	tree->right->left->right = new node;
	tree->right->left->right->left = new node;
	tree->left->data = 50;
	tree->left->left->data = 46;
	tree->left->left->left->data = 89;
	tree->left->left->right->data = 37;
	tree->left->left->left->left->data = 53;
	tree->left->left->left->right->data = 81;
	tree->left->left->left->right->right->data = 86;
	tree->right->data = 72;
	tree->right->left->data = 78;
	tree->right->right->data = 71;
	tree->right->left->left->data = 87;
	tree->right->left->right->data = 35;
	tree->right->left->right->left->data = 17;
}
int calculate_height_by_recursion(struct node* const &tree)
{
	if(tree != nullptr){
		int left = 1 + calculate_height_by_recursion(tree->left);
		int right = 1 + calculate_height_by_recursion(tree->right);
		return (left > right) ? left : right;
	}
	else return 0;
}
int calculate_height_without_recursion(struct node* const &tree)
{
	queue<struct node*> box;
	box.push(tree);
	int size = box.size();
	int height = 0;
	while(!box.empty())
	{
		for(int i = 0; i < size; ++i)
		{
			struct node* current = box.front();
			cout << current->data << " ";
			box.pop();
			if(current->left != nullptr) box.push(current->left);
			if(current->right != nullptr) box.push(current->right);
		}
		cout << endl;
		size = box.size();
		++height;
	}
	return height;
}
void show_tree_view(struct node* const &tree, string view)
{
	queue<struct node*> box;
	box.push(tree);
	cout << tree->data << " ";
	int size = box.size();
	while(!box.empty())
	{
		for(int i = 0; i < size; ++i)
		{
			struct node* current = box.front();
			box.pop();
			if(current->left != nullptr) box.push(current->left);
			if(current->right != nullptr) box.push(current->right);
		}
		size = box.size();
		if(size == 0) break;
		if(view == "left") cout << box.front()->data << " ";
		if(view == "right") cout << box.back()->data << " ";
	}
	cout << endl;
}
int main()
{
	struct node* tree = new node;
	construct(tree);
	int height = calculate_height_by_recursion(tree);
	cout << "height with recursion : " << height << endl;
	height = calculate_height_without_recursion(tree);
	cout << "height without recursion : " << height << endl;
	cout << "Left view of tree is : "; show_tree_view(tree, "left");
	cout << "Right view of tree is : "; show_tree_view(tree, "right");
	//cout << "Top view of tree is : "; show_tree_view(tree, "top");
	return 0;
}
