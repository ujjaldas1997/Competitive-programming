#include<bits/stdc++.h>
using namespace std;
void sort_nearly_sorted_array(vector<int> box, int k){
	int n = box.size();
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < k; ++i)
		pq.push(box[i]);
	for(int i = k; i < n; ++i){
		box[i - k] = pq.top();
		pq.pop();
		pq.push(box[i]);
	}
	for(int i = n - k; i < n; ++i){
		box[i] = pq.top();
		pq.pop();
	}
	
	for(int i : box)
		cout << i << " ";
	cout << endl;
	return;
}
int main()
{
	vector<int> box{6, 18, 2, 9, 34, 23, 57};
	int k = 3;
	sort_nearly_sorted_array(box, k);
	return 0;
}
