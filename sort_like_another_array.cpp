#include <bits/stdc++.h>
using namespace std;
void sort_like_another(vector<int> box, vector<int> ref){
    int n = box.size(), m = ref.size();
    map<int, int> mp;
    for(int i : box)
        if(mp.find(i) == mp.end())
            mp[i] = 1;
        else
            mp[i] += 1;
    
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < mp[ref[i]]; ++j)
            cout << ref[i] << " ";
        mp[ref[i]] = 0;
    }
    
    for(auto it = mp.begin(); it != mp.end(); ++it){
        for(int j = 0; j < it->second; ++j)
            cout << it->first << " ";
    }
    cout << endl;
    return;
}
int main() {
	//code
	int T = 0;
	cin >> T;
	for(int i = 0; i < T; ++i){
	    int n = 0, m = 0;
	    cin >> n >> m;
	    vector<int> box(n, 0), ref(m, 0);
	    for(int j = 0; j < n; ++j)
	        cin >> box[j];
	    for(int j = 0; j < m; ++j)
	        cin >> ref[j];
	    sort_like_another(box, ref);
	}
	return 0;
}
