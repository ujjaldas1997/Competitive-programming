#include <bits/stdc++.h>
using namespace std;
void showOut(vector<int> box){
    vector<int> pos, neg;
    int n = box.size();
    for(int i = 0; i < n; ++i){
        if(box[i] >= 0)
            pos.push_back(box[i]);
        else
            neg.push_back(box[i]);
    }
    int count = 0, i = 0, j = 0;
    while(i < pos.size() and j < neg.size()){
        if(count % 2 == 0){
            box[count] = pos[i];
            ++count;
            ++i;
        }
        else{
            box[count] = neg[j];
            ++count;
            ++j;
        }
    }
    if(j == neg.size())
        for(; i < pos.size(); ++i){
            box[count] = pos[i];
            ++count;
        }
    else
        for(; j < neg.size(); ++j){
            box[count] = neg[j];
            ++count;
        }
    //cout << count << i << j << endl;
    for(i = 0; i < n; ++i)
        cout << box[i] << " ";
    cout << endl;
    return;
}
int main() {
	//code
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i){
	    int n = 0;
	    cin >> n;
	    vector<int> box(n, 0);
	    for(int j = 0; j < n; ++j)
	        cin >> box[j];
	    showOut(box);
	}
	return 0;
}
