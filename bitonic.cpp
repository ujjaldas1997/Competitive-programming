#include <bits/stdc++.h>
using namespace std;
int bitonic(vector<int> box){
    int n = box.size(), recent = 0, k = 0;
    for(int i = 2; i < n; ++i){
        if(box[i] > box[i - 1] and box[i - 2] > box[i - 1]){
            k = max(k, i - recent);
            recent = i - 1;
        }
    }
    k = max(k, n - recent);
    return k;
}
int main() {
	//code
	int T = 0;
	cin >> T;
	for(int i = 0; i < T; ++i){
	    int n = 0;
	    cin >> n;
	    vector<int> box(n, 0);
	    for(int j = 0; j < n; ++j)
	        cin >> box[i];
	    cout << bitonic(box) << endl;
	}
	return 0;
}
