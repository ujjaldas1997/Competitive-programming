#include <bits/stdc++.h>
using namespace std;
bool isvalid(int i, int j, vector<vector<bool>>& visited, int& m, int& n){
    if(i >= 0 and i < n and j >= 0 and j < m and !visited[i][j]){
        visited[i][j] = 1;
        return 1;
    }
    else
        return 0;
}
void get_dist(vector<vector<bool>>& box, int i, int j, vector<vector<bool>>& visited){
    if(box[i][j]){
        cout << "0 ";
        return;
    }
    int n = visited.size(), m = visited[0].size(), cnt = 0;
    queue<pair<int, int>> curr, nxt;
    curr.push(make_pair(i, j));
    visited[i][j] = 1;
    while(!curr.empty()){
        ++cnt;
        while(!curr.empty()){
            auto k = curr.front();
            curr.pop();
            if(isvalid(k.first - 1, k.second, visited, m, n)){
                if(!box[k.first - 1][k.second])
                    nxt.push(make_pair(k.first - 1, k.second));
                else{
                    cout << cnt << " ";
                    return;
                }
            }
            if(isvalid(k.first + 1, k.second, visited, m, n)){
                if(!box[k.first + 1][k.second])
                    nxt.push(make_pair(k.first + 1, k.second));
                else{
                    cout << cnt << " ";
                    return;
                }
            }
            if(isvalid(k.first, k.second - 1, visited, m, n)){
                if(!box[k.first][k.second - 1])
                    nxt.push(make_pair(k.first, k.second - 1));
                else{
                    cout << cnt << " ";
                    return;
                }
            }
            if(isvalid(k.first, k.second + 1, visited, m, n)){
                if(!box[k.first][k.second + 1])
                    nxt.push(make_pair(k.first, k.second + 1));
                else{
                    cout << cnt << " ";
                    return;
                }
            }
        }
        curr = nxt;
        nxt = queue<pair<int, int>>();
    }
    return;
}
int main() {
	//code
	int T;
	cin >> T;
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    vector<vector<bool>> box(n, vector<bool>(m));
	    for(int i = 0; i < n; ++i)
	        for(int j = 0; j < m; ++j){
                int temp;
                cin >> temp;
	            box[i][j] = temp;
            }
	    vector<vector<bool>> visited(n, vector<bool>(m, 0));
	    for(int i = 0; i < n; ++i)
	        for(int j = 0; j < m; ++j){
	            get_dist(box, i, j, visited);
	            visited = vector<vector<bool>>(n, vector<bool>(m, 0));
	        }
	    cout << endl;
	}
	return 0;
}

