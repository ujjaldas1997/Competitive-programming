#include <bits/stdc++.h>
using namespace std;
void max_subarray(vector<int> box, int k){
    int n = box.size();
    deque<int> res;
    for(int i = 0; i < k; ++i){
        while(!res.empty() and box[i] >= box[res.back()])
            res.pop_back();
        res.push_back(i);
    }
    cout << box[res.front()] << " ";
    for(int i = k; i < n; ++i){
        while(!res.empty() and res.front() <= (i - k))
            res.pop_front();
        while(!res.empty() and box[i] >= box[res.back()])
            res.pop_back();
        res.push_back(i);
        cout << box[res.front()] << " ";
    }
    cout << endl;
    return;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    vector<int> box(n);
	    for(int j = 0; j < n; ++j)
	        cin >> box[j];
	    max_subarray(box, k);
	}
	return 0;
}
