#include<bits/stdc++.h>
using namespace std;
void max_index_diff(vector<int> box){
    int n = box.size();
    vector<int> left(n), right(n);
    left[0] = box[0], right[n - 1] = box[n - 1];
    for(int i = 1; i < n; ++i)
        left[i] = min(left[i - 1], box[i]);
    for(int j = n - 2; j >= 0; --j)
        right[j] = max(box[j], right[j + 1]);

    int max_diff = -1, i = 0, j = 0;
    while(i < n and j < n){
        if(n - i - 1 < max_diff) break;

        if(right[j] >= left[i]){
            max_diff = max(max_diff, j - i);
            ++j;
        }
        else
            ++i;
    }
    cout << max_diff << endl;
    return;
}
int main()
{
    vector<int> box{17}; //{9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    max_index_diff(box);
    return 0;
}

