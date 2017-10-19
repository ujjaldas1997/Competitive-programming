#include <bits/stdc++.h>
using namespace std;
void max_sum(vector<int> box){
    int n = box.size();
    box[2] += box[0];
    for(int i = 3; i < n; ++i)
        box[i] += max(box[i - 2], box[i - 3]);
    cout << *max_element(box.begin(), box.end()) << endl;
    return;
}
int main() {
	//code
	int T;
	cin >> T;
	while(T--){
	    int n = 0;
	    cin >> n;
	    vector<int> box(n);
	    for(int j = 0; j < n; ++j)
	        cin >> box[j];
	    max_sum(box);
	}
	return 0;
}
