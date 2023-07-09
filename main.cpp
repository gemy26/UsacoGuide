#include<bits/stdc++.h>



using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define  el '\n'
#define all(x) x.begin(),x.end()
ll mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N= 1e5 +1;

void setIO(string name = "") {
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool cmp(const pair<pair<int, int>,ll>& a,const pair<pair<int, int>,ll>& b){
    if ( a.first.second == b.first.second){if(a.second==b.second)return b.first.first>a.first.first; return b.second>a.second;}
    return a.first.second > b.first.second;
}


//bool cmp(const vector<int>&a,const vector<int>&b){return b[1] > a[1];}


int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
const char dc[4]={'U','R','D','L'};
#define HereWeGo() ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);

struct cow{
    int x;
    int y;
};
vector<vector<int>>G(1e5+1);
vector<vector<int>>comp;
vector<cow>v;
vector<int>temp;
bool vis[N];
void dfs(int node){
    if(vis[node])
        return;
    vis[node] = true;
    temp.pb(node);
    for(auto i : G[node]){

        dfs(i);

    }
}
void RunCase() {
int n,m;
cin >> n >> m;
v.resize(n);
memset(vis,false, sizeof(vis));


    for (int i = 0; i < n ; ++i) {
        cin >> v[i].x >> v[i].y;
    }
    for (int i = 0; i < m ; ++i) {
        int u,v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for (int i = 1; i <= n ; ++i) {
        if(!vis[i]){
            dfs(i);
            comp.pb(temp);
            temp.clear();
        }
    }
int ans = INT_MAX;
    for(auto i : comp){
        int mnx = INT_MAX;
        int mxx = 0;
        int mny = INT_MAX;
        int mxy = 0;
        for(auto j : i){
          mnx= min(mnx,v[j-1].x);
          mxx = max(mxx,v[j-1].x);

            mny= min(mny,v[j-1].y);
            mxy = max(mxy,v[j-1].y);

        }
        int temp = (2*(mxy-mny)) +( 2*(mxx-mnx));
        ans = min(ans,temp);

    }
    cout<<ans<<el;



}



















int main(){
    HereWeGo();
    setIO("fenceplan");

    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        //cout<<"Case #:"<<i+1<<el;

        RunCase();

    }
    return 0;

}