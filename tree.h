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
