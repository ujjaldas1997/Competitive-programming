#include<bits/stdc++.h>
using namespace std;
void closest_pair_sum(vector<int> A, vector<int> B, int k){
    int m = A.size(), n = B.size(), i = 0, j = m - 1, diff = INT_MAX, res_i = 0, res_j = 0;
    while(i < n and j >= 0){
        int sum = A[i] + B[j];
        if(diff > abs(k - sum)){
            diff = abs(k - sum);
            res_i = i;
            res_j = j;
        }
        if(k > sum)
            ++i;
        else
            --j;
    }
    cout << A[res_i] << " " << B[res_j] << endl;
    return;
}
int main()
{
    vector<int> A{1, 4, 5, 7}, B{10, 20, 30, 40};
    int k = 50;
    closest_pair_sum(A, B, k);
    return 0;
}

