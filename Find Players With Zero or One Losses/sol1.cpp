class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int,int> map;
        for(auto i : matches){
            map[i[0]];//store winner
            map[i[1]]++;//add number of losses
        }
        auto iter = map.begin();
        while(iter!=map.end()){
            if(iter->second==1){
                ans[1].push_back(iter->first);
            }else if(iter->second==0){
                ans[0].push_back(iter->first);
            }
            iter++;
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};