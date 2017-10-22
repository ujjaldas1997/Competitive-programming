#include <bits/stdc++.h>
using namespace std;
void show_idx(vector<int> box, int k){
    int n = box.size(), i = 0, right = 0;
    vector<int> index, left_sum, right_sum;
    while(box[i]){
        ++right;
        ++i;
    }
    left_sum.push_back(right);
    index.push_back(i);
    ++i;
    right = 0;
    for(; i < n; ++i){
        if(box[i])
            ++right;
        else{
            left_sum.push_back(right);
            right_sum.push_back(right);
            index.push_back(i);
            right = 0;
        }
    }
    right_sum.push_back(right);
    int maxm = 0, idx = 0;
    for(i = 0; i <= (int)(index.size() - k); ++i){
            cout << index.size() - k << endl;
        int temp = 0;
        for(int j = i; j < i + k; ++j){
            temp += left_sum[j] + right_sum[j];
        }
        if(temp > maxm){
            maxm = temp;
            idx = i;
        }
    }
    for(int j = idx; j < min((int)index.size(), idx + k); ++j)
        cout << index[j] << " ";
    cout << endl;
    return;
}
int main() {
	//code
	int t = 1;
	//cin >> t;
	while(t--){
	    int n = 11, k = 4;
	    //cin >> n;
	    vector<int> box{0, 0, 0, 1};//(n);
	    //for(int j = 0; j < n; ++j)
	    //    cin >> box[j];
	    //cin >> k;
	    show_idx(box, k);
	}
	return 0;
}

