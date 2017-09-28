#include <bits/stdc++.h>
using namespace std;
void show_sum(vector<int> box){
    int n = box.size(), sum = 0;
    sort(box.begin(), box.end());
    for(int i = 0; i < n / 2; ++i){
        sum -= 2 * box[i];
        sum += 2 * box[n - 1 - i];
    }
    cout << sum << endl;
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
	    show_sum(box);
	}
	return 0;
}
