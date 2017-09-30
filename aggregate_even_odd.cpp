#include <bits/stdc++.h>
using namespace std;
void aggregate_even_odd(vector<int> box){
    int n = box.size(), l = 0, r = n - 1;
    while(l < r){
        while(box[l] % 2 == 0)
            ++l;
        while(box[r] % 2 == 1)
            --r;
        if(l < r)
            swap(box[l], box[r]);
    }
    sort(box.begin(), box.begin() + l);
    sort(box.begin() + l, box.end());
    for(int i : box)
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
	    aggregate_even_odd(box);
	}
	return 0;
}
