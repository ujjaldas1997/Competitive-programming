#include <bits/stdc++.h>
using namespace std;
void show_abs_diff_sort(vector<int> box, int k){
    int n = box.size();
    multimap<int, int> m;
    for(auto i : box)
        m.insert(make_pair(abs(i - k), i));
    for(auto i : m)
        cout << i.second << " ";
    cout << endl;
    return;
}
int main() {
	//code
	int T = 0;
	cin >> T;
	for(int i = 0; i < T; ++i){
	    int n = 0, k = 0;
	    cin >> n >> k;
	    vector<int> box(n, 0);
	    for(int j = 0; j < n; ++j)
	        cin >> box[j];
	    show_abs_diff_sort(box, k);
	}
	return 0;
}
