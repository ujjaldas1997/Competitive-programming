#include<bits/stdc++.h>
using namespace std;
void lis(vector<int> box){
    int n = box.size();
    vector<int> l(n, 0), r(n, 0);
    for(int i = 1; i < n - 1; ++i){
        auto temp1 = vector<int>(box.begin(), box.begin() + i);
        auto temp2 = vector<int>(box.begin() + i + 1, box.end());
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        auto low = upper_bound(temp1.begin(), temp1.end(), box[i]);
        --low;
        l[i] = (*low > box[i]) ? 0 : *low;
        r[i] = (temp2.back() >= box[i]) ? temp2.back() : 0;
    }
    int maxm = 0;
    for(int i = 1; i < n - 1; ++i){
        maxm = max(maxm, box[i] * l[i] * r[i]);
    }
    cout << maxm << endl;
    return;
}
int main()
{
    vector<int> box{6, 7, 8, 1, 2, 3, 9, 10};
    lis(box);
    return 0;
}

