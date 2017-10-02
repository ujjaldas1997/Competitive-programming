/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this method*/
int maxLen(int arr[], int n)
{
//Your code here
    for(int i = 0; i < n; ++i)
        arr[i] = (arr[i] == 0) ? -1 : 1;
    int sum = 0, maxm = 0;
    unordered_map<int, int> um;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        if(sum == 0)
            maxm = max(maxm, i + 1);
        if(um.find(sum + n) != um.end())
            maxm = max(maxm, i - um[sum + n]);
        else
            um[sum + n] = i;
    }
    return maxm;
}
