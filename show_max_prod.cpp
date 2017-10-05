#include <bits/stdc++.h>
using namespace std;
void show_max_prod(vector<int> box){
    int n = box.size();
    int max_end = 1, min_end = 1, maxm = 0;
    for(int i : box){
        if(i > 0){
            max_end *= i;
            min_end = min(min_end * i, 1);
        }
        else if(i == 0){
            max_end = 1;
            min_end = 1;
        }
        else{
            int temp = max_end;
            max_end = max(min_end * i, 1);
            min_end = min(temp * i, 1);
        }
        maxm = max(maxm, max_end);
    }
    cout << maxm << endl;
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
	    show_max_prod(box);
	}
	return 0;
}
