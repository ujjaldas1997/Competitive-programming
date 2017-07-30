#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	vector<int> array = {3, 1, 4, 6, 5};
	sort(array.begin(), array.end());
	transform(array.begin(), array.end(), array.begin(), array.begin(), multiplies<int>() );
	int loop = array.size();
	for(auto i = loop - 1; i > 0; --i)
	{
		int sum = array[i];
		array.pop_back();
		int j = 0, k = array.size();
        	while(j < k)
	        {
        	        if(array[k] + array[j] == sum) break;
                	else if(array[k] + array[j] < sum) ++j;
	                else --k;
        	}
		if(array[k] + array[j] == sum)
	                cout << "Triplet found : " << "(" << sqrt(array[j]) << ", " << sqrt(array[k]) << ", " << sqrt(sum) << ")" << endl;
	}
}
