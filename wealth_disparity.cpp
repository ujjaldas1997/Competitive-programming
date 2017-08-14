#include<bits/stdc++.h>
using namespace std;
int max_wealth(auto id, auto pid){
	int maxm = -100000000;
	for(auto it = pid.begin(); it != pid.end(); ++it){
		int key = it->first;
		if(key != -1)
			maxm = max(maxm, id[key] - pid[key]);
	}
	return maxm;
}
int main()
{
	unordered_map<int, int> id, pid;
	int n = 0;
	cin >> n;
	int arr[n] = {0};
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		id[i + 1] = arr[i];
	}
	for(int i = 0; i < n; ++i){
		int p;
		cin >> p;
		pid[p] = arr[i];
	}
	cout << max_wealth(id, pid) <<endl;
	return 0;
}
