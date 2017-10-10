#include<bits/stdc++.h>
using namespace std;
#define N 3
vector<int> merge(vector<int> a, vector<int> b){
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<int> res;
    while(i < n and j < m){
        if(a[i] <= b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }
    for(; i < n; ++i)
        res.push_back(a[i]);
    for(; j < m; ++j)
        res.push_back(b[j]);
    return res;
}
int *mergeKArrays(int arr[][N], int k)
{
//code here
    vector<vector<int>> box(k, vector<int>(N, 0));
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < N; ++j)
            box[i][j] = arr[i][j];

    while(box.size() > 1){
        vector<vector<int>> res;
        vector<int> temp;
        int n = box.size();
        for(int i = 0; i < n; i += 2){
            if(i + 1 < n){
                temp = merge(box[i], box[i + 1]);
                res.push_back(temp);
            }
            else
                res.push_back(box[i]);
        }
        box = res;
    }
    int *a = new int[N * k], count =0;
    for(auto i : box)
        for(auto j : i)
            a[count++] = j;
    return a;
}
int main(){
    int arr[3][3] = {2, 4, 5, 1, 3, 7, 6, 8, 9};
    int *p = mergeKArrays(arr, 3);
    for(int i = 0; i < 9; ++i)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}

