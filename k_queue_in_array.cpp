#include<bits/stdc++.h>
using namespace std;
#define s 6
struct Queue{
    int f = -1;
    int b = -1;
};
class Qg{
private:
    int arr[s];
    int next[s];
    Queue* q;
    int free;
public:
    Qg(int k){
        arr[s] = {0,};
        free = 0;
        for(int i = 0; i < s; ++i)
            next[i] = i + 1;
        next[s - 1] = -1;
        q = new Queue[k];
    }
    void push(int id, int value);
    void pop(int id);
};
void Qg::push(int id, int value){
    if(free == -1){
            cout << "Queue is full, Push operation aborted" << endl;
            return;
    }
    if(q[id].f == -1 and q[id].b == -1){
        int temp = free;
        free = next[temp];
        arr[temp] = value;
        q[id].f = temp;
        q[id].b = temp;
        next[temp] = temp;
    }
    else{
        int temp = free;
        free = next[temp];
        arr[temp] = value;
        next[q[id].b] = temp;
        q[id].b = temp;
        next[temp] = temp;
    }
    cout << value << " placed successfully in queue " << id << endl;
    return;
}
void Qg::pop(int id){
    if(q[id].f == -1 and q[id].b == -1){
        cout << "Queue is empty, Pop operation aborted" << endl;
        return;
    }
    else{
        int v = arr[q[id].f];
        int temp = q[id].f;
        q[id].f = next[temp];
        next[temp] = free;
        free = temp;
        if(temp == q[id].b){
            q[id].f = q[id].b = -1;
        }
        cout << v << " poped successfully from queue " << id << endl;
    }
    return;
}
int main()
{
    Qg mq(3);
    mq.push(0, 2);
    mq.push(0, 4);
    mq.push(1, 3);
    mq.push(1, 7);
    mq.push(1, 1);
    mq.push(0, 6);
    mq.push(0, 9);
    mq.pop(0);
    mq.pop(0);
    mq.pop(0);
    mq.pop(0);
    return 0;
}

