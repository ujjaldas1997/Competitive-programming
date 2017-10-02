/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The function returns a vector containing the 
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> A, int N)
{
   //Your code here
   vector<int> grt(N, -1), lss(N, -1);
   int minm = 0, maxm = N - 1;
   for(int i = 1; i < N; ++i){
       minm = (A[minm] < A[i - 1]) ? minm : i - 1;
       if(A[i] > A[minm])
        lss[i] = minm;
   }
   for(int i = N - 2; i >= 0; --i){
       maxm = (A[maxm] > A[i + 1]) ? maxm : i + 1;
       if(A[i] < A[maxm])
        grt[i] = maxm;
   }
   vector<int> ret;
   for(int i = 0; i < N; ++i){
       if(lss[i] != -1 and grt[i] != -1){
           ret.push_back(A[lss[i]]);
           ret.push_back(A[i]);
           ret.push_back(A[grt[i]]);
           break;
       }
   }
   return ret;
}
