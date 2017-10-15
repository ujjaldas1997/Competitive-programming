#include<bits/stdc++.h>
using namespace std;
void printC(vector<int> C, int len){
    for(int i = 0; i <= len; ++i)
        cout << C[i] << " ";
    cout << endl;
    return;
}
void show_perm(vector<int> A, vector<int> B, vector<int> C, int i, int j, int len, bool flag){
    int m = A.size(), n = B.size();
    if(flag){
        if(len)
            printC(C, len);
        for(int k = i; k < m; ++k){
            if(!len){
                C[len] = A[k];
                show_perm(A, B, C, k + 1, j, len, 0);
            }
            else{
                if(A[k] > C[len]){
                    C[len + 1] = A[k];
                    show_perm(A, B, C, k + 1, j, len + 1, 0);
                }
            }
        }
    }
    else{
        for(int l = j; l < n; ++l){
            if(B[l] > C[len]){
                C[len + 1] = B[l];
                show_perm(A, B, C, i, l + 1, len + 1, 1);
            }
        }
    }
}
int main()
{
    vector<int> A{10, 15, 25}, B{1, 5, 20, 30};
    int m = A.size(), n = B.size();
    vector<int> C(m + n, 0);
    show_perm(A, B, C, 0, 0, 0, 1);
    return 0;
}

