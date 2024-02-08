#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;

    while(tt--)
    {
        int n;
        cin >> n;
        string s,cop;
        cin >> s;
        cop = s;

        string sub="";
        vector<int>pos;
        for(int i=n-1; i>=0; i--)
        {
           if(n-1==i)
           {
               sub += s[i];
               pos.push_back(i);
           }
           else if(sub.back()<=s[i])
           {
              sub += s[i];
              pos.push_back(i);
           }
        }

        int cnt=0,i=sub.size()-1;
        while(i>=0 && sub.back()==sub[i])
        {
            cnt++;
            i--;
        }

        reverse(sub.begin(),sub.end());
        for(int i=0; i<sub.size(); i++)
        {
            s[pos[i]]=sub[i];
        }

        sort(cop.begin(),cop.end());
        if(cop==s)
        cout << sub.size()-cnt <<endl;
        else
        cout <<"-1"<<endl;

    }
}
