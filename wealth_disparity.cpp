#include<bits/stdc++.h>
using namespace std;
int max_diff = INT_MIN;
void dfs(map<int, vector<int>> &tree, int root, int maxm, int value[]){
	if(tree[root].empty()){
		max_diff = max(max_diff, maxm - value[root]);
		//cout << "Root = " << root << ", maxm = " << maxm << ", max_diff = " << max_diff << endl;
		return;
	}
	//maxm = max(maxm, value[root]);
	//max_diff = max(max_diff, maxm - value[root]);
	for(int i = 0; i < tree[root].size(); ++i){
		int child = tree[root][i];
		maxm = max(maxm, value[root]);
		max_diff = max(max_diff, maxm - value[child]);
		//cout << "Child = " << child << ", maxm = " << maxm << ", max_diff = " << max_diff << endl;
		dfs(tree, child, maxm, value);
	}
}
int main()
{
	map<int, vector<int>> tree;
	int n = 0, root;
	int maxm = INT_MIN;
	cin >> n;
	int value[n + 1] = {0};
	for(int i = 1; i <= n; ++i)
		cin >> value[i];
	for(int i = 1; i <= n; ++i){
		int p;
		cin >> p;
		if(p == -1) root = i;
		else tree[p].push_back(i);
	}
	/*for(auto it = tree.begin(); it != tree.end(); ++it){
		cout << "Parent : " << it->first << " Child : ";
		for(int i = 0; i < it->second.size(); ++i)
			cout << it->second[i] << " ";
		cout << endl;
	}*/
	maxm = value[root];
	dfs(tree, root, maxm, value);
	cout << max_diff << endl;
	return 0;
}
