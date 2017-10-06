#include <bits/stdc++.h>
using namespace std;
void replace_with_greatest_element(vector<int> box){
    int n = box.size();
    int maxm = box[n - 1];
    box[n - 1] = -1;
    for(int i = n - 2; i >= 0; --i){
        if(box[i] < maxm)
            box[i] = maxm;
        if(box[i] > maxm)
            swap(box[i], maxm);
    }

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
	    replace_with_greatest_element(box);
	}
	return 0;
}
