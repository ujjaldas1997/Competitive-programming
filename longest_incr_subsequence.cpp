#include<bits/stdc++.h>
using namespace std;
void lis(vector<int> box){
	int n = box.size();
	vector<int> lis_value(n, 1);
	for(int i = 1; i < n; ++i)
		for(int j = 0; j < i; ++j)
			if(box[i] >= box[j] and lis_value[i] < lis_value[j] + 1)
				lis_value[i] = lis_value[j] + 1;
	
	//int maxm = *max_element(lis_value.begin(), lis_value.end());
	//cout << distance(lis_value.begin(), max_element(lis_value.begin(), lis_value.end())) << endl;
	int index = distance(lis_value.begin(), max_element(lis_value.begin(), lis_value.end()));
	int value = *max_element(lis_value.begin(), lis_value.end());
	cout << box[index] << " ";
	--value;
	for(int i = index - 1; i >= 0; --i){
		if(lis_value[i] == value){
			cout << box[i] << " ";
			--value;
		}
		if(value == 0)
			break;
	}
	cout << endl;
	return;
}
int main()
{
	vector<int> box{2, 5, 3, 7, 11, 8, 10, 13, 6};
	lis(box);
	return 0;
}
