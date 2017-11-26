#include<bits/stdc++.h>
using namespace std;
void sum_of_max_min_of_subarray_size_k(vector<int> box, int k){
    deque<int> tmax{0}, tmin{0};
    for(int i = 1; i < k; ++i){
        while(!tmax.empty() and box[tmax.back()] <= box[i])
            tmax.pop_back();
        tmax.push_back(i);
        while(!tmin.empty() and box[tmin.back()] >= box[i])
            tmin.pop_back();
        tmin.push_back(i);
    }
    cout << box[tmax.front()] + box[tmin.front()] << " ";
    //cout << box[tmax.back()] << " " << box[tmin.back()] << " " << endl;
    for(int i = k; i < box.size(); ++i){
        while(!tmax.empty() and tmax.front() < i - k)
            tmax.pop_front();
        while(!tmax.empty() and box[tmax.back()] <= box[i])
            tmax.pop_back();
        tmax.push_back(i);
        while(!tmin.empty() and tmin.front() < i - k)
            tmin.pop_front();
        while(!tmin.empty() and box[tmin.back()] >= box[i])
            tmin.pop_back();
        tmin.push_back(i);
        cout << box[tmax.front()] + box[tmin.front()] << " ";
        //cout << box[tmax.back()] << " " << box[tmin.back()] << " " << endl;
    }
    return;
}
int main()
{
    vector<int> box{2, 5, -1, 7, -3, -1, -2};
    sum_of_max_min_of_subarray_size_k(box, 4);
    return 0;
}

