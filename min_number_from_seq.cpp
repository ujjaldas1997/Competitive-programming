#include<bits/stdc++.h>
using namespace std;
void smallest_seq(vector<pair<char, int>> box){
    int max_so_far = 1;
    string res = "";
    auto it = box.begin();
    if(it->first == 'D'){
        for(int i = max_so_far + it->second; i >= max_so_far; --i)
                res += to_string(i);
            max_so_far += it->second;
            ++it;
    }
    else if(it->first == 'I'){
        for(int i = max_so_far; i < max_so_far + it->second; ++i)
                res += to_string(i);
        max_so_far += it->second;
        it++;
        if(it != box.end()){
            res += to_string(it->second + max_so_far);
            max_so_far += it->second;
            for(int i = max_so_far - 1; i > max_so_far - 1 - it->second; --i)
                res += to_string(i);
            it++;
        }
        else
            res += to_string(max_so_far);
    }
    while(it != box.end()){
        if(it->first == 'I'){
            for(int i = max_so_far + 1; i < max_so_far + it->second; ++i)
                res += to_string(i);
            max_so_far += it->second;
            it++;
            if(it != box.end()){
                res += to_string(it->second + max_so_far);
                max_so_far += it->second;
                for(int i = max_so_far - 1; i > max_so_far - 1 - it->second; --i)
                    res += to_string(i);
                it++;
            }
            else
                res += to_string(max_so_far);
        }
        else{
            for(int i = max_so_far + it->second; i > max_so_far; --i)
                res += to_string(i);
            max_so_far += it->second;
            ++it;
        }
    }
    cout << res << endl;
    return;
}
/*
void smallest_seq(string inp){
    stack<int> box;
    string res;
    for(int i = 0; i <= inp.size(); ++i){
        box.push(i + 1);
        if(inp[i] == 'I' or i == inp.size()){
            while(!box.empty()){
                res += to_string(box.top());
                box.pop();
            }
        }
    }
    cout << res << endl;
    return;
}
*/
int main()
{
    string inp = "DIDI";
    vector<pair<char, int>> box;
    box.push_back(make_pair(inp[0], 1));
    for(unsigned int i = 1; i < inp.size(); ++i){
        if(inp[i] == box.back().first)
            box.back().second += 1;
        else
            box.push_back(make_pair(inp[i], 1));
    }
    smallest_seq(box);
    //smallest_seq(inp);
    return 0;
}

