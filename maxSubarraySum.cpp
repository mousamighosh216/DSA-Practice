#include <iostream>
#include <vector>
using namespace std;


// maximum subarray sum using KADANE'S ALGO and DIVIDE AND CONQUER

// DIVIDE AND CONQUER
// TC:- O(nlogn)

int findSubarray(vector<int> &nums,int l,int r){
    if(l>r) return 0;
    if(l==r) return arr[l];
    int m=(l+r)/2;

    int lsum = findSubarray(nums,l,m);
    int rsum = findSubarray(nums,m+1,r);
    int csum = contiSum(nums,l,m,r);

    if(lsum>=rsum && lsum>=csum) return lsum;
    else if(rsum>=lsum && rsum>=csum) return rsum;
    else return csum;
}

int contiSum(vector<int> &nums,int l,int m,int r) {
    int sum=0, lsum=INT_MIN;
    for(int i=m;i>=0;i--){
        sum+=nums[i];
        if(sum>lsum) lsum=sum;
    }

    int sum=0, rsum=INT_MIN;
    for(int i=m+1;i<=r;i++){
        sum+=nums[i];
        if(sum>rsum) rsum=sum;
    }

    return (lsum+rsum);
}

// KADANE'S ALGO
// TC:- O(n)
int kadanesAlgo(vector<int> & nums) {
    int n=nums.size();

    int sum=0,mxans=-1;
    for(int i=0;i<n;i++){
        sum+=nums[i];

        // suppose sum becomes -ve it means we will not inc. 
        if(sum<0) sum=0;
        mxans=max(mxans,sum);
    }
}


int main(){
    vector<int> nums={1,2,3,-1,3,-3};
    

    // using divide-n-conquer
    cout << findSubarray(nums,0,nums.size()-1);

    // kadane
    cout << kadanesAlgo(nums);
}

