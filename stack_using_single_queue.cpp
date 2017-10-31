#include<bits/stdc++.h>
using namespace std;
class Queue{
private:
    queue<int> line;
public:
    void push(int element);
    void pop();
};
void Queue::push(int element){
    line.push(element);
    cout << element << " pushed successfully." << endl;
    return;
}
void Queue::pop(){
    if(line.size() == 0){
        cout << "Empty queue, can't pop." << endl;
        return;
    }
    int n = line.size() - 1;
    for(int i = 0; i < n; ++i){
        int temp = line.front();
        line.pop();
        line.push(temp);
    }
    int element = line.front();
    line.pop();
    cout << element << " popped successfully." << endl;
    return;
}
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    return 0;
}

