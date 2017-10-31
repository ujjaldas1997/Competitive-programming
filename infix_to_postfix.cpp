#include <bits/stdc++.h>
using namespace std;
void postfix(string s){
    map<char, int> prd{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
    stack<char> op;
    string res;
    for(auto i : s){
        if((i >= 'A' and i <= 'Z') or (i >= 'a' and i <= 'z'))
            res += i;
        else if(i == '(')
            op.push(i);
        else if(i == ')'){
            while(op.top() != '('){
                res += op.top();
                op.pop();
            }
            op.pop();
        }
        else if(op.empty() or (prd[i] > prd[op.top()]))
            op.push(i);
        else{
            while(!op.empty() and !(prd[i] > prd[op.top()])){
                res += op.top();
                op.pop();
            }
            op.push(i);
        }
    }
    while(!op.empty()){
        res += op.top();
        op.pop();
    }
    cout << res << endl;
    return;
}
int main() {
	//code
	int t = 1;
	//cin >> t;
	while(t--){
	    string s = "a+b*(c^d-e)^(f+g*h)-i";
	    //getline(cin, s);
	    postfix(s);
	}
	return 0;
}

