// rod cutting extended version

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int N=1e5+2;
vector<int> max_rev[N], optimal_sz[N],price[N];

// TC:= O(N^2) 
// here we are updating cst to get the max cost price as well as storing optimal sizes 
// bottom up approach is like a subproblem graph, n=4     4->3->2->1 here 4 is also directly connected to 3,2,1 ans 3 to 2,1 and so on


// bottom up approach
int ext_rod_cutting(int i) {
    max_rev[0]=0;
    for(int j=1;j<i;j++) {
        int cst= INT_MIN;
        for(int k=1;k<j;k++) {
            if(cst < price[i]+max_rev[j-k]) {
                cst = price[i]+max_rev[j-k];
                optimal_sz[j] = k;
            }
        }
        max_rev[j]=cst;
    }

    // return max_rev[i] and optimal_sz[i]
}
