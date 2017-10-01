#include <bits/stdc++.h>
using namespace std;
void max_bitonic(vector<int> box){
    int n = box.size();
    vector<int> lis(n, 1), lds(n, 1);

    for(int i = 1; i < n; ++i)
        for(int j = 0; j < i; ++j)
            if((box[i] > box[j]) and (lis[i] < lis[j] + 1))
                lis[i] = lis[j] + 1;

    for(int i = n - 2; i >= 0; --i)
        for(int j = n - 1; j > i; --j)
            if((box[i] > box[j]) and (lds[i] < lds[j] + 1))
                lds[i] = lds[j] + 1;

    int maxm = 0;
    for(int i = 0; i < n; ++i)
        maxm = max(maxm, lis[i] + lds[i] - 1);
    cout << maxm << endl;
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
	    max_bitonic(box);
	}
	return 0;
}
