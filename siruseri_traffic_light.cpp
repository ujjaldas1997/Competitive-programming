#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;
int min_time(const auto& time, const auto& visited, const auto& n){
    int minm = INT_MAX, index;
    for(int i = 0; i < n; ++i)
        if(!visited[i] and minm > time[i])
        {
            minm = time[i];
            index = i;
        }
    return index;
}
int dijkstra_siruseri(const int& source, const int& destination, const int& n, const int& m, const auto& wait_node, const auto& wait_edge)
{
    vector<int> time(n, INT_MAX);
    vector<bool> visited(n, false);

    time[source] = 0;
    int curr_time = 0, wait_time;

    for(int i = 1; i < n; ++i){
        int u = min_time(time, visited, n), temp;
        temp = time[u] % wait_node[u];
        if(temp == 0)
	        wait_time = 0;
	    else
	        wait_time = wait_node[u] - temp;
        visited[u] = true;
        for(int v = 0; v < n; ++v)
            if(!visited[v] and wait_edge[u][v]){
                if(time[v] > time[u] + wait_edge[u][v] + wait_time)
                    time[v] = time[u] + wait_edge[u][v] + wait_time;
            }
    }

    /*for(int i = 0; i < n; ++i)
        cout << i << '\t' << time[i] << endl;*/
    return time[destination];
}

int main()
{
    int source, destination, n, m;
    cin >> source >> destination >> n >> m;
    vector<int> wait_node(n, 0);
    vector<vector<int>> wait_edge(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
        cin >> wait_node[i];
    for(int i = 0; i < m; ++i){
        int j, k;
        cin >> j >> k;
        --j; --k;
        cin >> wait_edge[j][k];
        wait_edge[k][j] = wait_edge[j][k];
    }
    --source; --destination;
    int time = dijkstra_siruseri(source, destination, n, m, wait_node, wait_edge);
    cout << time;
    return 0;
}
