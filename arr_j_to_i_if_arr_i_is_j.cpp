#include<bits/stdc++.h>
using namespace std;
void show_arr(vector<int> box){
    int n = box.size();
    for(int i = 0; i < n; ++i){
        if(box[i] < n){
            int index = i, old = box[index];
            while(box[old] < n){
                    int temp = box[old];
                    box[old] = index + n;
                    index = old;
                    old = temp;
            }
        }
    }
    for(int i : box)
        cout << i - n << " ";
    cout << endl;
    return;
}
int main()
{
    vector<int> box{2, 0, 1, 4, 5, 3};
    show_arr(box);
    return 0;
}

