#include<bits/stdc++.h>
using namespace std;
int min_swap(vector<int> box, vector<int> bpair){
    int n = box.size();
    int c = 0;
    for(int i = 1; i < n; i += 2){
        if(box[i + 1] != bpair[box[i]]){
            ++c;
            auto it = find(box.begin() + i, box.end(), bpair[box[i]]);
            int index = it - box.begin();
            swap(box[i + 1], box[index]);
        }
    }
    return c;
}
int main()
{
    vector<int> box{0, 3, 5, 6, 4, 1, 2};
    vector<int> bpair{0, 3, 6, 1, 5, 4, 2};
    cout << min_swap(box, bpair);
    return 0;
}

