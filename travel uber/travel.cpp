#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;

bool pos(int val,vector<int>& nums,int n){  //this function tell us if the cost val can finish the trip or not
    int len=nums.size();
    int curr=0;
    for(int i=0;i<len;i++){
        curr+=val/nums[i] ;//how many trips
        if(curr>=n)
            return true;
    }
    return false;
}

int solve(vector<int> &nums,int n){
    int l=0,r=nums[nums.size()-1]*n;
    int ans=nums[nums.size()-1]*n;
    while(l<r){
        int mid=l+(r-l)/2;
        if(pos(mid ,nums, n)){
            ans=min(ans,mid);
            r=mid;
        }
        else
            l=mid+1;
    }
    return ans;
    
}
int main(){
    vector<int> vec={1,3,5,7,8};
    int n=10;

    // vector<int> vec={1,2};
    // int n=3;
    cout<<solve(vec,n);   
}