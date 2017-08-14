#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int, int> id;
	int n = 0, maxm = -100000000;
	cin >> n;
	int arr[n] = {0};
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		id[i + 1] = arr[i];
	}
	for(int i = 0; i < n; ++i){
		int p;
		cin >> p;
		if(p != -1){
			maxm = max(maxm, id[p] - arr[i]);
			//cout << "maxm = " << maxm << " id[p] = " << id[p] << " arr[i] = " << arr[i] << endl;
		}
	}
	cout << maxm <<endl;
	return 0;
}
