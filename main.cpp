// this file contains all algorithms/dfs/bfs/dsu realted content 


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


// MERGE SORT //

#include <bits/stdc++.h>
using namespace std;


const int N=1e5+10;
int a[N];


    void merge(int l,int r,int mid){
        int l_size=mid-l+1;
        int L[l_size+1];
        int r_size =r-mid;
        int R[r_size+1];
        for(int i=0;i<l_size;i++){
            L[i]=a[i+l];
        }
        for(int i=0;i<r_size;i++){
            R[i]=a[i+mid+1];
        }
        L[l_size]=R[r_size]=INT_MAX;
        int l_i=0,r_i=0;
        for(int i=l;i<=r;i++){
            if(L[l_i] <= R[r_i]){
                a[i]=L[l_i];
                l_i++;
            } else {
                a[i]=R[r_i];
                r_i++;
            } 
        }
    }
    void mergesort(int l,int r){
        if(l==r)return;
        int mid=(l+r)/2;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,r,mid);
    }


int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int l,r;
    cin >> l >> r;
    mergesort(l,r);

    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
}
