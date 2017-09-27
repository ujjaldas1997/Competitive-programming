#include <bits/stdc++.h>
using namespace std;
void show_max_min(vector<int> box){
    int n = box.size();
    vector<int> temp;
    for(int i = 0; i < n / 2; ++i){
        temp.push_back(box[n - 1 - i]);
        temp.push_back(box[i]);
    }
    if(n % 2 != 0)
        temp.push_back(box[(n - 1) / 2]);
    for(auto i : temp)
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
