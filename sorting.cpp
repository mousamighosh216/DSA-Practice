// MERGE SORT //

#include <iostream>
#include <vector>
#include <algorithm>
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

// QUICK SORT

int partition(vector<int> &v, int l, int h) {
    int pivot = v[h];
    int low = l-1;

    for(int j=l;j<=h-1;j++) {
        if(v[j]<pivot) {
            low++;
            swap(v[low],v[j]);
        }
    }

    swap(v[low+1],v[h]);
    return low+1;
}

void quicksort(vector<int> &v,int l,int h) {
    if(l<h) {
        int pi = partition(v,l,h);
        quicksort(v,l,pi-1);
        quicksort(v,pi+1,h);
    }
}

int main() {
    vector<int> v = {10,9,8,6,1,5};
    int n = v.size();
    quicksort(v,0,n-1);

    for(auto i:v) cout << i << " ";
}