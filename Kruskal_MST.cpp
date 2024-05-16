#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define faster_code ios_base::sync_with_stdio(false);cin.tie(NULL);

struct node{
    int par;
    int rank;
};

struct Edge{
    int src;
    int dst;
    ll wt;
};

vector<node> dsuf;
vector<Edge> mst;

int find(int v){
    if(dsuf[v].par==-1) return v;
    return dsuf[v].par=find(dsuf[v].par);
}

void union_op(int frm,int to){
    if(dsuf[frm].rank>dsuf[to].rank){
        dsuf[to].par=frm;
    }
    else if(dsuf[frm].rank < dsuf[to].rank){
        dsuf[frm].par=to; 
    }
    else{
        dsuf[frm].par = to;
        dsuf[to].rank +=1;
    }
}

bool comparator(Edge a,Edge b){
    return a.wt < b.wt;
}

void Kruskals(vector<Edge> &edge, int v, int e){
    sort(edge.begin(),edge.end(),comparator);
    int i=0,j=0; 

    while(i<v-1 && j<e) 
    {
        int frm_par = find(edge[j].src);
        int to_par = find(edge[j].dst);

        if(frm_par==to_par){
            j++;
            continue;
        }

        union_op(frm_par,to_par);
        mst.push_back(edge[j]);
        i++;
        j++; 
    }
}

void printnst(){
    cout << "MST Path is : \n";
    
    ll cost = 0;
    for(Edge x:mst )
    {
        cost += x.wt;

        cout << x.src << " -> " << x.dst <<" = " << x.wt << endl;
    }

    cout << "Total cost of MST = " << cost <<endl; 
}

int main(){
    faster_code;
    int e,v;
    cin >> v >> e;

    dsuf.resize(v+1); 

    for(int i=1;i<=v;++i) 
    {
        dsuf[i].par=-1;
        dsuf[i].rank=0;
    }

    vector<Edge> Eglist;
    Edge temp;

    for(int i=0; i<e; i++)
    {
        int frm,to,wt;
        cin >> frm >> to >> wt;

        temp.src = frm;
        temp.dst = to;
        temp.wt=wt;

        Eglist.push_back(temp);
    }

    Kruskals(Eglist,v,e);
    
    printnst();
    
    return 0;
}
