#include<bits/stdc++.h>
using namespace std;
void ksmall_pair(vector<int> A, vector<int> B, int k){
    int n1 = A.size(), n2 = B.size();
    vector<int> index(n1, 0);
    for(int x = 0; x < k; ++x){
        int pos = index[0], min_sum = INT_MAX;
        for(int i = 0; i < n1; ++i)
            if(A[i] + B[index[i]] < min_sum and index[i] < n2){
                min_sum = A[i] + B[index[i]];
                pos = i;
            }
        cout << A[pos] << "\t" << B[index[pos]] << endl;
        ++index[pos];
    }
    return;
}
int main()
{
    vector<int> A{1, 3}, B{2, 4, 5};
    ksmall_pair(A, B, 3);
    return 0;
}

