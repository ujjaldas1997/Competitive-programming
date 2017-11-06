#include<bits/stdc++.h>
using namespace std;
void check_perm(queue<int> A, queue<int> B){
    stack<int> v;
    while(!A.empty()){
        v.push(A.front());
        A.pop();
        while(!v.empty() and (B.front() == v.top())){
            v.pop();
            B.pop();
        }
    }
    if(B.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
}
int main(){
    queue<int> A({1, 2, 3}), B({3, 1, 2});
    check_perm(A, B);
    return 0;
}

