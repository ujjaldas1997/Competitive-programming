#include<iostream>
#include<limits.h>
using namespace std;
class kstack{
private:
    int *arr;
    int* next;
    int* top;
    int free;
    int n, k;
public:
    kstack(int n, int k);
    void push(int element, int j);
    int pop(int j);
    bool isempty(int j);
    bool isfull(int j);
    void content();
};
kstack::kstack(int n, int k){
    this->n = n, this->k = k;
    arr = new int[n];
    next = new int[n];
    top = new int[k];
    for(int i = 0; i < k; ++i)
        top[i] = -1;
    for(int i = 0; i < n; ++i)
        next[i] = i + 1;
    next[n - 1] = -1;
    free = 0;
}
bool kstack::isempty(int j){
    return (top[j] == -1) ? 1 : 0;
}
bool kstack::isfull(int j){
    return (free == -1) ? 1 : 0;
}
void kstack::push(int element, int j){
    if(isfull(j)){
        cout << "Stack overflow." << endl;
        return;
    }
    int i = free;
    free = next[i];
    arr[i] = element;
    next[i] = top[j];
    top[j] = i;
}
int kstack::pop(int j){
    if(isempty(j)){
        cout << "Stack underflow error : ";
        return INT_MAX;
    }
    int i = top[j];
    top[j] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}
void kstack::content(){
    cout << "Content of array is : ";
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl << "Content of next is : ";
    for(int i = 0; i < n; ++i)
        cout << next[i] << " ";
    cout << endl << "Content of top is : ";
    for(int i = 0; i < k; ++i)
        cout << top[i] << " ";
    cout << endl << "Free = " << free << endl;
}
int main()
{
    kstack k(7, 2);
    k.push(7, 0);
    //k.content();
    k.push(3, 0);
    //k.content();
    k.push(9, 1);
    //k.content();

    k.push(5, 0);
    //k.content();
    k.push(2, 1);
    //k.content();
    k.push(0, 1);
    //k.content();
    k.push(4, 1);
    //k.content();
    k.push(10, 1);

    //k.content();

    cout << k.pop(0) << endl;
    cout << k.pop(0) << endl;
    cout << k.pop(0) << endl;
    cout << k.pop(0) << endl;
    cout << k.pop(1) << endl;
    cout << k.pop(1) << endl;
    cout << k.pop(1) << endl;
    cout << k.pop(1) << endl;
    k.content();
    return 0;
}

