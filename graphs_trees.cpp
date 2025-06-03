// BFS/DFS/DSU


// multi-source BFS // 

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N=1e3+2;
const int INF=1e9+10;
int val[N][N];
int vis[N][N];
int lvl[N][N];
int n,m;

vector<pair<int,int>> mv={
    {1,0},{-1,0},{0,1},{0,-1},
    {1,1},{1,-1},{-1,1},{-1,-1}
};

bool check(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            val[i][j]=0;
            lvl[i][j]=INF;
            vis[i][j]=0;
        }
    }
}

int bfs(int mx){
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(val[i][j]==mx){
                q.push({i,j});
                vis[i][j]=1;
                lvl[i][j]=0;
            }
        }
    }

    int ans=0;
    while(!q.empty()){
        pair<int,int> q_val = q.front();
        q.pop();

        int q_x = q_val.first;
        int q_y = q_val.second;

        for(auto movement:mv){
            int ch_x=movement.first+q_x;
            int ch_y = movement.second+q_y;

            if(!check(ch_x,ch_y)) continue;
            if(vis[ch_x][ch_y]) continue;

            q.push({ch_x,ch_y});
            vis[ch_x][ch_y]=1;
            lvl[ch_x][ch_y]=lvl[q_x][q_y]+1;

            ans=max(ans,lvl[ch_x][ch_y]);
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        reset();

        cin >> n >> m;

        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> val[i][j];
                if(mx<val[i][j]) mx=val[i][j];
            }
        }

        cout << bfs(mx) << endl;
    }
    return 0;
}


// UNION BY SIZE //

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+5;
int par[N];
int sz[N];

int findPar(int n){
  if(par[n]==n)
    return n;

  return par[n]=findPar(par[n]);
}

void unbysz(int u,int v){
  int pu = findPar(u);
  int pv = findPar(v);
  if(pu==pv) return;

  if(sz[pu]<sz[pv]) swap(pu,pv);
  par[pv] = pu;
  sz[pu]+=sz[pv];
}

void solve(){
  int n;
  cin >> n;

  for(int i=1;i<=n;i++){
    par[i]=i;
    sz[i]=1;
  }

  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >>v;
    unbysz(u,v);
  }

  for(int i=1;i<=n;i++){
    cout << par[i] << " "<<sz[i] << "\n";
  }
}

int main() {
    solve(); 
}



