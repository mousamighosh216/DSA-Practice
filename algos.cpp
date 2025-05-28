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


