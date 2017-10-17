#include<bits/stdc++.h>
using namespace std;
int count_pair(vector<int> box, int mid){
    int cnt = 0;
    for(int i = 0; i < box.size(); ++i)
        cnt += upper_bound(box.begin() + i, box.end(), box[i] + mid) - (box.begin() + i + 1);
    return cnt;
}
void ksmallest_diff(vector<int> box, int k){
    sort(box.begin(), box.end());
    int high = box.back() - box.front(), low = box[1] - box[0];
    for(int i = 2; i < box.size(); ++i)
        low = min(low, box[i + 1] - box[i]);

    while(low < high){
        int mid = (low + high) / 2;
        if(count_pair(box, mid) < k)
            low = mid + 1;
        else
            high = mid;
    }
    cout << low << endl;
    return;
}
int main()
{
    vector<int> box{1, 3, 5, 7, 8, 9, 11, 13, 16};
    ksmallest_diff(box, 13);
    return 0;
}

