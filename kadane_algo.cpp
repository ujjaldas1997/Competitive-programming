#include<bits/stdc++.h>
using namespace std;
void show_max_sum(vector<int> box){
	int n = box.size();
	int max_so_far = INT_MIN, max_end = 0;
	for(int i = 0; i < n; ++i){
		max_end += box[i];
		if(max_so_far < max_end)
			max_so_far = max_end;
		if(max_end < 0)
			max_end = 0;
	}
	cout << max_so_far << endl;
	return;
}
int main()
{
	vector<int> box{-2, -3, 4, -1, -2, 1, 5, -3};
	show_max_sum(box);
	return 0;
}
