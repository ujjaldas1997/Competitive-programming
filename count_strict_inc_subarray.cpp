#include <bits/stdc++.h>
using namespace std;
void count_subarray(vector<int> box){
    int n = box.size(), last = 0, maxm = 0;
    for(int i = 0; i < n - 1; ++i){
        if(box[i + 1] <= box[i]){
            int temp = i - last;
            maxm += temp * (temp + 1) / 2;
            last = i + 1;
        }
    }
    maxm += (n - 1 - last) * (n - last) / 2;
    cout << maxm << endl;
    return;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> box(n);
	    for(int j = 0; j < n; ++j)
	        cin >> box[j];
	    count_subarray(box);
	}
	return 0;
}
