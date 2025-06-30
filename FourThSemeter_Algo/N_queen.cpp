#include<bits/stdc++.h>
using namespace std;

int x[50];
bool flag = false;

bool isplace(int k,int i){
    for(int j=1; j<k; j++){
        if(x[j]==i || abs(x[j]-i) == abs(j-k))
        {
            return false;
        }
    }
    return true;
}

void print(int n)
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(x[i]==j){
                cout << "Q" << " ";
            }
            else{
                cout <<"*" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void n_queen(int k,int n){
    
    if(flag) return;
    
    for(int i=1; i<=n; i++){
        if(isplace(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                print(n);
                flag = true;
            }
            else{
                n_queen(k+1,n);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    n_queen(1,n);
}