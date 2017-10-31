#include<bits/stdc++.h>
using namespace std;
int main()
{
    auto comp = [](pair<int, int> a, pair<int, int> b){return a.first < b.first;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
    int arr[] = {9, 1, 3, 5, 7, 2};
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        pq.push(make_pair(i, arr[i]));
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
        cout << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}

