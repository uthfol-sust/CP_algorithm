#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ull unsigned long long
#define faster_code ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define PI 3.14159265


const ll mod =1e9 + 7;
const int N=1e5+2;


void solve()
{
 double a[3];
       for(ll i=0;i<3;i++)cin>>a[i];
       sort(a,a+3);
       
       cout<<180-(((asin(a[0])*180)/acos(-1.0))+((asin(a[1])*180)/acos(-1.0)))<<endl;
  
}

int main()
{
    faster_code;

  int tt;
  cin >> tt;
  while(tt--){
   solve();
   }
    return 0;
}