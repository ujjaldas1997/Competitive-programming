#include<bits/stdc++.h>
using namespace std;
void print_vec(vector<vector<int>> stat){
	for(int i = 0; i < stat.size(); ++i){
		for(int j = 0; j < stat.size(); ++j)
			cout << stat[i][j] << " ";
		cout << endl;
	}
	return;
}
void print_substring(string word){
	int n = word.size(), maxm = 1, p = 0;
	vector<vector<int>> stat(n, vector<int>(n, 0));
	for(int i = 0; i < n; ++i)
		stat[i][i] = 1;
	for(int j = 0; j < n - 1; ++j)
		if(word[j] == word[j + 1]){
			stat[j][j + 1]  = 1;
			maxm = 2;
			p = j;
		}
	for(int len = 2; len < n; ++len)
		for(int j = 0; j < (n - len); ++j)
			if((word[j] == word[j + len]) and (stat[j + 1][j + len - 1] == 1)){
				stat[j][j + len]  = 1;
				maxm = len + 1;
				p = j;
			}
	print_vec(stat);
	cout << maxm << endl;
	cout << word.substr(p, maxm) << endl;
	return;
}
int main()
{
	//int n;
	//cin >> n;
	string word = "abcbcabbacba";
	//cin >> word;
	print_substring(word);
	return 0;
}

