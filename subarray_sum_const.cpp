#include<iostream>
#include<vector>
using namespace std;
int main()
{
        vector<int> array = {2, 4, 2, 42, 5};
        int sum = 43;
        for(int i = 1; i < array.size(); ++i) array[i] += array[i - 1];
        array.insert(array.begin(), 0);
        int i = 0, j = 1;
        while(i < array.size() - 1 and j < array.size())
        {
                if(array[j] - array[i] == sum) break;
                else if(array[j] - array[i] < sum) ++j;
                else ++i;
        }
        if(array[j] - array[i] == sum)
                cout << ++i << " " << j << endl;
        else
                cout << "-1" << endl;
        return 0;
}
