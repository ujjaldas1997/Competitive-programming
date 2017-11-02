#include<bits/stdc++.h>
using namespace std;
void slide_min_k(vector<int> box, int k){
    int n = box.size(), i;
    deque<int> window;
    for(i = 0; i < k; ++i){
        if(window.empty())
            window.push_back(i);
        else if(!window.empty() and box[i] >= box[window.back()]);
        else
            window.push_back(i);
    }
    cout << box[window.back()] << " ";
    for(; i < n; ++i){
        while(!window.empty() and window.front() <= (i - k))
            window.pop_front();
        if(window.empty())
            window.push_back(i);
        else if(!window.empty() and box[i] >= box[window.back()]);
        else
            window.push_back(i);
        cout << box[window.back()] << " ";
    }
    cout << endl;
    return;
}
int main()
{
    vector<int> box{1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    slide_min_k(box, k);
    return 0;
}

