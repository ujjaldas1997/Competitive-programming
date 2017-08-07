#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct item{
	int key = 0,day = 0, fine = 0;
};
bool comp(const item &a, const item& b)
{
	return a.day * b.fine < a.fine * b.day;
}
int main()
{
	int n = 0;
	cin >> n;
	vector<item> job(n);
	for(int i = 0; i < n; ++i){
		job[i].key = i + 1;
		cin >> job[i].day >> job[i].fine;
	}
	stable_sort(job.begin(), job.end(), comp);
	for(auto it = job.begin(); it != job.end(); ++it)
		cout << it->key << endl;
}
