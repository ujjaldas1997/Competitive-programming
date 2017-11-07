#include<bits/stdc++.h>
using namespace std;
void show(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return;
}
void interleave(queue<int> q){
    int n = q.size();
    stack<int> temp, A, B;
    for(int i = 0; i < n / 2; ++i){
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty()){
        A.push(temp.top());
        temp.pop();
    }
    for(int i = 0; i < n / 2; ++i){
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty()){
        B.push(temp.top());
        temp.pop();
    }
    while(!A.empty() and !B.empty()){
        q.push(A.top());
        A.pop();
        q.push(B.top());
        B.pop();
    }
    show(q);
}
int main()
{
    queue<int> q({11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
    interleave(q);
    return 0;
}

