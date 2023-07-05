
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int longest =1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int it : st){
            if(st.find(it-1) == st.end()){ // if you not find prev ele, we want to find the start of sequence
             // start new sequence
               int cnt = 1;
               int ele = it;
               while(st.find(ele+1) != st.end()){
                    // if you found next ele then continue the loop 
                    ele = ele+1;
                    cnt += 1;
               }
               longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
