#include <bits/stdc++.h>
using namespace std;
void decode(string s){
    stack<string> v;
    for(char i : s){
        if(i == '[')
            v.push("");
        else if(i >= '0' and i <= '9' and (v.empty() or (v.top()[0] >= 'a' and v.top()[0] <= 'z'))){
            v.push("");
            v.top() += i;
        }
        else if(i == ']'){
            string temp = v.top();
            v.pop();
            int p = stoi(v.top());
            v.pop();
            v.push(temp);
            for(int j = 1; j < p; ++j)
                v.top() += temp;
            temp = v.top();
            v.pop();
            if(v.empty())
                v.push(temp);
            else
            v.top() += temp;
        }
        else
            v.top() += i;
    }
    cout << v.top() << endl;
}
int main() {
	//code
	int t = 1;
	//cin >> t;
	while(t--){
	    string s = "3[a3[b]1[ab]]";
	    //cin >> s;
	    decode(s);
	}
	return 0;
}

