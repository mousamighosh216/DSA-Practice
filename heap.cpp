#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// HEAP SORT
void heapify(vector<int> &v, int n, int i) {
    int lrg=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && v[l]>v[lrg])
        lrg=l;
    if(r<n && v[r]>v[lrg])
        lrg=r;
    if(lrg!=i) 
        swap(v[i],v[lrg]);
    
    heapify(v,n,lrg);
}

void heapsort(vector<int> &v) {
    int n=v.size();

    for(int i=n/2-1;i>=0;i--) 
        heapify(v,n,i);

    for(int i=n-1;i>0;i--) {
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}

int main() {
    vector<int> v={3,5,4,2,6};
    heapsort(v);
}

// TODO: Priority Queue