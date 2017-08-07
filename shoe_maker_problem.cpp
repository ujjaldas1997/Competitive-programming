/*
A shoemaker has N orders from customers that he must execute. The shoemaker can work on only one job each day. For each job i,
it takes Ti days for the shoemaker to finish the job, where Ti is an integer and (1 ≤ Ti ≤ 1000). For each day of delay before
starting to work for the job i, shoemaker must pay a fine of Si (1 ≤ Si ≤ 10000) rupees. Your task is to help the shoemaker
find the sequence in which to complete the jobs so that his total fine is minimized. If multiple solutions are possible, print
the one that is lexicographically least (i.e., earliest in dictionary order).
Input format

The first line of input contains an integer N (1 ≤ N ≤ 100000). Each of the next N lines contains two space separated 
integers: the time Ti and fine Si for job i, 1 ≤ i ≤ N.

Output format

You program should print the sequence of jobs with minimal fine. Each job should be represented by its position in the input
and each job should appear on a new line, by itself. If multiple solutions are possible, print the one that is 
lexicographically least (i.e., earliest in dictionary order).

Sample input

4
3 4
1 1000
2 2
5 5
Sample output

2
1
3
4
*/
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
