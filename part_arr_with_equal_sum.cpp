#include <bits/stdc++.h>
using namespace std;
bool check_arr(vector<int> box, int sum){
    int n = box.size();
    if(sum != 0 and n == 0) return false;
    if(sum == 0) return true;
    vector<int> temp(box.begin(), box.end() - 1);
    if(box.back() > sum)
        return check_arr(temp, sum);
    else
        return check_arr(temp, sum)
            or check_arr(temp, sum - box.back());
}
void show_part(vector<int> box){
    int sum = 0;
    for(int i : box)
        sum += i;
    if(sum % 2 != 0)
        cout << "NO" << endl;
    else{
        bool res = check_arr(box, sum / 2);
        if(res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
	    show_part(box);
	}
	return 0;
}

