#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i){
	    vector<int> box;
	    int n;
	    cin >> n;
	    int t;
	    for(int j = 0; j < n; ++j){
	    	cin >> t;
	        box.push_back(t);
	    }
	    
	    vector<int> cum_sum = {0};
	    cum_sum.push_back(box[0]);
	    int count = 0;
	    for(int j = 1; j < box.size(); ++j)
	        cum_sum.push_back(cum_sum[j] + box[j]);
	    for(int j = 0; j < cum_sum.size(); ++j){
	        for(int k = j + 2; k < cum_sum.size(); k += 2){
	            int mid = j + k / 2;
	            if(cum_sum[mid] - cum_sum[j] == cum_sum[k] - cum_sum[mid])
	                count = max(count, k - j);
	        }
	    }
	    cout << "Count : " << count << endl;
	}
	return 0;
}
