#include<bits/stdc++.h>
using namespace std;
void show(multiset<int, greater<int>> ms){
    cout << "Multimap : " << endl;
    for(int i : ms)
        cout << i << " ";
    cout << endl << endl;
    return;
}
void count_smaller(vector<int> box){
    int n = box.size();
    vector<int> res(n, 0);
    multiset<int, greater<int>> ms;
    for(int i = n - 1; i >= 0; --i){
        ms.insert(box[i]);
        res[i] = distance(ms.upper_bound(box[i]), ms.end());
        /*if(res[i] == 15){
            cout << "Element : " << box[i] << endl;
            show(ms);
        }*/
    }
    for(int i : res)
        cout << i << " ";
    cout << endl;
    return;
}
int main()
{
    vector<int> box{12, 1, 2, 3, 0, 11, 4};//{468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403,
     //154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};
    count_smaller(box);
    return 0;
}

