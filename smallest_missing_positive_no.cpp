#include <bits/stdc++.h>
using namespace std;
void show_vec(vector<int> box){
    for(int i : box)
        cout << i << " ";
    cout << endl;
    return;
}
void show_smallest(vector<int> box){
    sort(box.begin(), box.end());
    box.erase(unique(box.begin(), box.end()), box.end());
    int n = box.size(), count = 1, i = 0;
    for(; i < n; ++i)
        if(box[i] > 0)
            break;
    for(; i < n; ++i){
        if(box[i] != count)
            break;
        ++count;
    }
    show_vec(box);
    cout << count << endl;
    return;
}
int main() {
	//code
	int t = 0;
	cin >> t;
	while(t--){
	    int n = 0;
	    cin >> n;
	    vector<int> box(n);
	    for(int j = 0; j < n; ++j)
	        cin >> box[j];
	    show_smallest(box);
	}
	return 0;
}
