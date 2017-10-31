#include<bits/stdc++.h>
using namespace std;
int getId(vector<vector<int>> M)
{
    //Your code here
    int n = M.size();
    if (n == 1)
        return -1;
    int i = 0, C = 1;
    while (i < n and C < n) {
        if (M[i][C])
            i = max (C + 1, i + 1);
        else
            C = max (C + 1, i + 1);
    }

    for (int j = 0; j < n; ++j) {
        if (C < n and j != C and !M[j][C])
            return -1;
        if (i < n and j != i and !M[j][i])
            return -1;
    }
    return C >= n ? i : C;
}
int main()
{
    vector<vector<int>> M{{0, 1, 1, 0, 0, 0},
                          {1, 0, 1, 1, 0, 1},
                          {0, 0, 0, 0, 0, 0},
                          {1, 0, 1, 0, 1, 0},
                          {1, 0, 1, 1, 0, 0},
                          {1, 1, 1, 1, 1, 0}};
    cout << getId(M);
    return 0;
}

