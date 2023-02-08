
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count=0;
        int temp;
        for(int i = 0; i<=n;i++){
            temp=i;
            count=0;
            while(temp!=0){
                count +=temp%2;
                temp=temp/2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
