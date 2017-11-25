#include<bits/stdc++.h>
using namespace std;
void show(vector<int> box){
    for(int i : box)
        cout << i << " ";
    cout << endl;
    return;
}
void show_largest_multiple_3(vector<int> box){
    vector<int> rem0,rem1, rem2;
    for(int i : box){
        if(i % 3 == 0)
            rem0.push_back(i);
        else if(i % 3 == 1)
            rem1.push_back(i);
        else
            rem2.push_back(i);
    }
    sort(rem1.begin(), rem1.end(), greater<int>());
    sort(rem2.begin(), rem2.end(), greater<int>());
    int n = min(rem1.size(), rem2.size());
    for(int i = 0; i < n; ++i){
        rem0.push_back(rem1[i]);
        rem0.push_back(rem2[i]);
    }
    sort(rem0.begin(), rem0.end(), greater<int>());
    show(rem0);
    return;
}
int main()
{
    vector<int> box{8, 1, 7, 6, 0};
    show_largest_multiple_3(box);
    return 0;
}

