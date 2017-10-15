#include<bits/stdc++.h>
using namespace std;
void arranged_array(vector<int> box, vector<int> ind){
    int n = box.size();
    for(int i = 0; i < n; ++i){
        if(ind[i] < n){
            int index = i, des = ind[index], old = box[index];
            while(ind[index] < n){
                int temp = box[des];
                box[des] = old;
                ind[index] += n;
                index = des;
                old = temp;
                des = ind[index];
            }
        }
    }
    for(int i : box)
        cout << i << " ";
    cout << endl;
    return;
}
int main()
{
    vector<int> box{50, 40, 70, 60, 90};
    vector<int> ind{3, 0, 4, 1, 2};
    arranged_array(box, ind);
    return 0;
}

