#include<bits/stdc++.h>
using namespace std;
class Stack{
private:
    stack<int> k;
    int minm;
public:
    void push(int element);
    void pop();
    void get_min();
};
void Stack::push(int element){
    if(k.empty()){
        k.push(element);
        minm = element;
    }
    else if(element >= minm)
        k.push(element);
    else{
        k.push(element * 2 - minm);
        minm = element;
    }
    cout << element << " pushed successfully" << endl;
    get_min();
    return;
}
void Stack::pop(){
    int temp;
    if(k.empty()){
        cout << "Stack empty" << endl;
        return;
    }
    else if(k.top() >= minm)
        temp = k.top();
    else{
        temp = minm;
        minm = minm * 2 - k.top();
    }
    k.pop();
    cout << "Poped element is : " << temp << endl;
    get_min();
    return;
}
void Stack::get_min(){
    cout << "Minimum element is " << minm << endl;
    return;
}
int main()
{
    Stack k;
    k.push(8);
    k.push(9);
    k.push(3);
    k.push(2);
    k.push(7);
    k.push(5);
    k.pop();
    k.pop();
    k.pop();
    k.pop();
    k.pop();
    k.pop();
    k.pop();
    return 0;
}

