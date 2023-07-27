#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &loc){
    int n=loc.size();
    sort(loc.begin(),loc.end());  //sorts with starting co-ordinates of cab.
    int ans=0;
    for(int i=0;i<n;i++){
        int start=loc[i][0],end=loc[i][1];
        while(i<n && loc[i][0]<= end){
            end=max(end,loc[i][1]);
            i++;
        }
        i--;
        ans+=(end-start+1);
    }
    return ans;
}
int main(){
    vector<vector<int>> loc={{4,7},{-1,5},{3,6}};
    cout<<solve(loc);   
}