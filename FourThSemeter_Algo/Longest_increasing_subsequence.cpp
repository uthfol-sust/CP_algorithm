#include<bits/stdc++.h>
using namespace std;

int lisEndingAtIdx(int idx, vector<int> arr, vector<int> memo){
   if(idx==0)return 1;

   if(memo[idx]!=-1) return memo[idx];

   int mx = 1;
   
   for(int i=0; i<idx; i++){
     if(arr[i]<arr[idx])
     {
        mx = max(mx, lisEndingAtIdx(i , arr , memo)+1);
     }
   }

   memo[idx ] = mx;
   return memo[idx];
}

int main(){
    vector <int> arr =  { 10, 22, 9, 33, 21, 50, 41, 60 };

    int n = arr.size();
    vector<int> memo(n,-1);

    int res = 1;
    for (int i = 1; i < n; i++)
        res = max(res, lisEndingAtIdx( i , arr, memo));

    cout << res ;
}