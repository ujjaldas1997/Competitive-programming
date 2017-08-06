#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int mod = 1000000000 + 7;
    string s = {};
    cin >> s;
    int arr1[26] = {0}, arr2[26][26] = {0}, arr3[26] = {0};
    int count = 0;
    for(const auto& i : s){
        int index = i - 'a';
        count += (arr3[index] % mod);
        count = count % mod;
        for(int j = 0; j < 26; ++j){
            arr3[j] += (arr2[j][index] % mod);
            arr3[j] = arr3[j] % mod;
        }
        for(int j = 0; j < 26; ++j){
            arr2[j][index] += (arr1[j] % mod);
            arr2[j][index] = arr2[j][index] % mod;
        }
        ++arr1[index];
        arr1[index] = arr1[index] % mod;
    }
    cout << count;
    return 0;
}
