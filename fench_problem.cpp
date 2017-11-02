#include <bits/stdc++.h>

using namespace std;
void fence(vector<long long> box, long long k){
    long long l, r, mid, n;
    n = box.size();
    l = 0, r = *max_element(box.begin(), box.end());
    while(l < r){
        long long c = 0;
        mid = ((l + r) >> 1) + 1;
        for(int i = 0; i < n; ++i)
            c += box[i] / mid;
        if(c >= k)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
}
int main() {
    long long n = 3, k = 4;
    //cin >> n >> k;
    vector<long long> box{15, 10, 8};
    fence(box, k);
    return 0;
}

