#include <bits/stdc++.h>
using namespace std;
bool comp(string a, string b){
    return (a + b < b + a) ? 1 : 0;
}
void show(vector<string> box){
    for(string i : box)
        cout << i << " ";
    cout << endl;
    return;
}
void fetch_greatest_no(vector<string> box){
    sort(box.begin(), box.end(), comp);
    //show(box);
    string res = "";
    for(string i : box)
        res = i + res;
    cout << res << endl;
    return;
}
int main() {
	//code
	int T = 0;
	cin >> T;
	for(int i = 0; i < T; ++i){
	    int n = 0;
	    cin >> n;
	    vector<string> box(n, "");
	    for(int j = 0; j < n; ++j){
	        int temp;
	        cin >> temp;
	        box[j] = to_string(temp);
	    }
	    fetch_greatest_no(box);
	}
	return 0;
}
