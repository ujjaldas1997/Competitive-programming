#include <bits/stdc++.h>
using namespace std;
void stock_span(vector<int> box){
    int n = box.size();
    stack<int> s;
    for(int i = 0; i < n; ++i){
        while(!s.empty() and box[i] > box[s.top()])
            s.pop();
        if(s.empty())
            cout << i + 1 << " ";
        else
            cout << i - s.top() << " ";
        s.push(i);
    }
    cout << endl;
    return;
}
int main() {
	//code
	int t = 1;
	//cin >> t;
	while(t--){
	    //int n = 0;
	    //cin >> n;
	    vector<int> box{100, 80, 60, 70, 60, 75, 85};
	    //for(int j = 0; j < n; ++j)
	    //    cin >> box[j];
	    stock_span(box);
	}
	return 0;
}

