#include<iostream>
#include "tree.h"
using namespace std;
int diam_tree(struct node* head, int& diameter){
	if(head == nullptr)
		return -1;
	int h_l = 1 + diam_tree(head->left, diameter);
	int h_r = 1 + diam_tree(head->right, diameter);
	diameter = max(diameter, h_l + h_r + 1);
	return max(h_l, h_r);
}
int main()
{
	node* tree = new node;
    construct(tree);
    int diameter = 0;
    diam_tree(tree, diameter);
    cout << diameter << endl;
    return 0;
}
