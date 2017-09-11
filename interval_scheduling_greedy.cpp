#include<bits/stdc++.h>
using namespace std;
int stop = 0;
void showvec(vector<pair<int, int>> sch){
	for(int i = 0; i < sch.size(); ++i){
		cout << "Start : " << sch[i].first << ", End : " << sch[i].second << endl;
	}
	return;
}
bool comp(pair<int, int> inst1, pair<int, int> inst2){
	return inst1.second < inst2.second;
}
int int_schedule(vector<pair<int, int>> sch){
	int event = 0;
	while(!sch.empty()){
		vector<int> to_del;
		++event;
		//cout << "Selected event : Start = " << sch.front().first << ", End = " << sch.front().second << endl; 
		stop = sch[0].second;
		sch.erase(sch.begin());
		sch.erase(remove_if(sch.begin(), sch.end(),
			[&sch](const pair<int, int> &x){
				return x.first < stop;
				}), sch.end());
	}
	return event;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> sch(n);
	for(int i = 0; i < n; ++i){
		cin >> sch[i].first >> sch[i].second;
		sch[i].second += sch[i].first;
	}
	sort(sch.begin(), sch.end(), comp);
	//showvec(sch);
	cout << int_schedule(sch) << endl;
	return 0;
}
