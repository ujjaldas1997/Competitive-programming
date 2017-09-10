#include<bits/stdc++.h>
using namespace std;
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
	int event = 0, stop = 0;
	while(!sch.empty()){
		++event;
		stop = sch[0].second;
		sch.erase(sch.begin());
		for(int i = 0; i < sch.size(); ++i){
			if(sch[i].first < stop){
				swap(sch[i], sch.back());
				sch.pop_back();
			}
		}
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
