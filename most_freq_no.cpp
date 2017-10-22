#include <bits/stdc++.h>
using namespace std;
void max_freq(vector<int> box, int k){
    int n = box.size(), maxm = 0, idx = -1;
    for(int i = 0; i < n; ++i){
        box[box[i] % k] += k;
    }
    for(int i = 0; i < n; ++i){
        int temp = box[i] / k;
        if(temp > maxm){
            idx = i;
            maxm = temp;
        }
    }
    cout << idx << endl;
    return;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n = 0, k = 0;
	    cin >> n >> k;
	    vector<int> box(n);
	    for(int j = 0; j < n; ++j)
	        cin >> box[j];
	    max_freq(box, k);
	}
	return 0;
}
