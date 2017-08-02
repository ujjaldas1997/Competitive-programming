#include<algorithm>
#include<iostream>
#include<vector>
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
void find_max_min(node* const &tree, int& maximum, int& minimum, int hd)
{
	if(tree == nullptr) return;
	if(maximum < hd) ++maximum;
	if(minimum > hd) --minimum;
	find_max_min(tree->left, maximum, minimum, hd - 1);
	find_max_min(tree->right, maximum, minimum, hd + 1);
}
void find_node(node* const &tree, int i, int hd, int level, vector<pair<auto, auto>> &level_data)
{
	if(tree == nullptr) return;
	if(i == hd)
	{
		//cout << "data : " << tree->data << " level : " << level << endl;
		level_data.push_back(pair<int, int> (level, tree->data));
	}
	find_node(tree->left, i, hd - 1, ++level, level_data);
	find_node(tree->right, i, hd + 1, ++level, level_data);
}
void vertical_traversal(node* const &tree, int& maximum, int& minimum, vector<int> &top, vector<int> &bottom)
{
	cout << "Vertical tree traversal is as follows :" << endl;
	for(int i = minimum; i <= maximum; ++i)
	{
		vector<pair<int, int>> level_data;
		find_node(tree, i, 0, 0, level_data);
		sort(level_data.begin(), level_data.end());
		for(vector<pair<int, int>>::iterator it = level_data.begin(); it != level_data.end(); ++it)
			cout << it->second << " ";
		cout << endl;
		top.push_back(level_data.begin()->second);
		bottom.push_back(level_data.rbegin()->second);
		if(level_data[level_data.size() - 1].first == level_data[level_data.size() - 2].first) 
			bottom.push_back(level_data[level_data.size() - 2].second);
	}
}
int main()
{
	node* tree = new node;
	construct(tree);
	vector<int> top, bottom;
	int maximum = 0, minimum = 0;
	find_max_min(tree, maximum, minimum, 0);
	vertical_traversal(tree, maximum, minimum, top, bottom);
	cout << "Top view is as :" <<endl;
	for(vector<int>::iterator it = top.begin(); it != top.end(); ++it)
		cout << *it << " ";
	cout << endl << "Bottom view as :";
	for(vector<int>::iterator it = bottom.begin(); it != bottom.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
