#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

void reverse_node(node* &start, node* &end){
	if (start == end);
	else{
		node* temp1 = start, *temp2 = start->next;
		while (temp2 != end){
			node* temp = temp2->next;
			temp2->next = temp1;
			temp1 = temp2;
			temp2 = temp;
		}
		temp2->next = temp1;
		start->next = nullptr;
	}
}
struct node *reverse(struct node *head, int k)
{
	// Complete this method
	node* start, *end, *pre, *post;
	start = head;
	end = head;
	if (end->next != nullptr)
		for (int i = 1; i < k; ++i){
			end = end->next;
			if (end->next == nullptr) break;
		}
	pre = end->next;
	reverse_node(start, end);
	head = end;
	post = pre;
	while (post != nullptr){
		if (post->next != nullptr)
			for (int i = 1; i < k; ++i){
				post = post->next;
				if (post->next == nullptr) break;
			}
		start->next = post;
		start = pre;
		end = post;
		pre = post->next;
		post = pre;
		reverse_node(start, end);
	}
	pre = nullptr;
	return head;
}

int main(int argc, char *argv[])
{
	int k = 0;
	cin >> k;
	node* head = new node, *temp1, *temp2;
	cin >> head->data;
	temp1 = head;
	int d;
	while (cin >> d){
		temp2 = new node;
		temp2->data = d;
		temp1->next = temp2;
		temp1 = temp2;
	}
	temp1->next = nullptr;
	head = reverse(head, k);
	return 0;
}
