#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// for DAGs:- nodes connected through directed edges and graph doesnt contains a cycle
// using bfs to implement topo sort

// TC:- O(V+E)

vector<int> topo(int v,vector<int> g[]) {
    int indeg[v] = {0};
    for(int i=0;i<v;i++) {
        for(auto it:g[i]) {
            indeg[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++) {
        if(indeg[i]==0)
            q.push(i);
    }

    vector<int> topo_arr;
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        topo_arr.push_back(num);

        for(auto it:g[num]) {
            indeg[it]--;
            if(indeg[it]==0)
                q.push(it);
        }
    }

    return topo_arr;
}

int main() {
    int v=6;
    vector<int> g[6] = {{},{},{3},{1},{0,1},{0,2}};
    vector<int> ans = topo(v,g);
}