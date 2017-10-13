#include<bits/stdc++.h>
using namespace std;
int index_of_zero(vector<int> box){
    int n = box.size(), left = 0, right = 0, index = 0, maxm = 0, max_index = 0;
    for(int i = 0; i < n; ++i){
        if(box[i])
            ++right;
        else{
            index = i;
            if(maxm < left + right){
                maxm = left + right;
                max_index = index;
            }
            left = right;
            right = 0;
        }
    }
    if(box.back() and maxm < left + right)
        max_index = index;
    return max_index;
}
int main()
{
    vector<int> box{1, 1, 1, 1, 0};
    cout << index_of_zero(box) << endl;
    return 0;
}

