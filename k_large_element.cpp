#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
inline void swap(auto &a, auto &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void heapify(auto &con)
{
	int n = con.size(), u, temp;
	int i = n - 1, flag = pow(2, int(log2(n))) - 2;
	while(i > 0)
	{
		if(i % 2 == 0)
		{
			int j = i;
			--i;
			u = j / 2 - 1;
			temp = (con[j] > con[i]) ? j : i;//temp = (con[j] < con[i]) ? j : i; #for min heap
		}
		else	u = (i - 1) / 2, temp = i;
		while(u <= flag)
		{
			if(con[u] < con[temp]) //if(con[u] > con[temp]) #for min heap
			{
				swap(con[u], con[temp]);
				u = temp;
				int l1 = 2 * u + 1, l2 = 2 * u + 2;
				temp = (con[l1] > con[l2]) ? l1 : l2;//temp = (con[l1] < con[l2]) ? l1 : l2; #for min heap
				if(l2 == n) temp = l1;
			}
			else	break;
		}
		--i;
	}
}
int main()
{
	//vector<int> con = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> con = {1, 2, 3, 4, 5, 6, 7};
	heapify(con);
	for(auto i : con) cout << i << endl;
	cout << "How many largest elements? : ";
	int k;
	cin >> k;
	for(int i = 0; i < k; ++i)
	{
		swap(con.front(), con.back());
		cout << con.back() << "\t" ;
		con.pop_back();
		heapify(con);
	}
	return 0;
}
