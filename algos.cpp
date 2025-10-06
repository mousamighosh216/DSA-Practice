#include <iostream>
using namespace std;

// floyd warshall
// tc:= O(n^3)
// this algo is used to find shortest path between any two random points, not like dijkstra's in which we calculate dist. from a specific vertex

const int INF=1e9+5;
const int N=505;
int g[N][N];

int main() {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) g[i][j]=0;
            g[i][j]=INF;
            // PRE-INITIALIZE
        }
    }

    int n;
    cin >> n;
    // vertices 

    // double loop to input weights at resp. indices 

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][k]!= INF && g[k][j]!=INF)
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                // dist. clac. via vertex k
            }
        }
    }

}


// multistage graph 
//tc:= O(n^2)

const int n=9,INF=1e9+10;
int dist[n][n];

int main() {
    int cost[n],d[n],p[5];
    cost[n-1]=0;

    int m;
    cin >> m;
    for(int i=0;i<m;i++) {
        int x,y,wt;
        cin >> x >> y >> wt;
        dist[x][y]=wt;
    }

    for(int i=n-2;i>=0;i--) {
        int mn=INF;
        for(int j=i+1;j<n;j++) {
            if(dist[i][j]!=0 && dist[i][j]+cost[j]<mn) {
                mn=dist[i][j]+cost[j];
                d[i]=j;
            }
        }
        cost[i]=mn;
    }

    p[0]=1;p[4]=n-1;
    for(int i=1;i<4;i++) {
        p[i]=d[p[i-1]];
    }

    for(int i=0;i<5;i++) cout << p[i] << (i==4?"\n":" "); 
    return 0;
}



