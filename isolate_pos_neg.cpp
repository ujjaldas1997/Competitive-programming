#include <bits/stdc++.h>
using namespace std;
void mov_neg(vector<int> box){
    int n = box.size();
    vector<int> pos, neg;
    for(auto i : box){
        if(i >= 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }
    int count = 0;
    for(auto i : pos){
        box[count] = i;
        ++count;
    }
    for(auto i : neg){
        box[count] = i;
        ++count;
    }
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
	    mov_neg(box);
	}
	return 0;
}
