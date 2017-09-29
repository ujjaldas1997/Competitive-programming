#include <bits/stdc++.h>
using namespace std;
void show_max_min(vector<int> box){
    int n = box.size(), l = 0, r = n - 1, maxm = box.back() + 1;
    for(int i = 0; i < n; ++i){
    	if(i % 2 == 0){
    		box[i] += (box[r] % maxm) * maxm;
    		--r;
    	}
    	else{
    		box[i] += (box[l] % maxm) * maxm;
    		++l;
    	}
    }
    for(int i = 0; i < n; ++i)
    	box[i] /= maxm;
    for(auto i : box)
    	cout << i << " ";
    cout << endl;
    return;
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
	        cin >> box[j];
	    show_max_min(box);
	}
	return 0;
}
