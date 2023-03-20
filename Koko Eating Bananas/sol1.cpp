
class Solution {
public:
    bool is_k_suitable(vector<int>& piles, int h, int k){
        int count = 0;
        for(auto i:piles){
            double temp = i /double(k);
            count+=ceil(temp);
        }
        if (count<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max_iter = max_element(std::begin(piles), std::end(piles));
        int max = *max_iter;
        //the possible k is in 1 to max
        int start=1;
        int end =max;
        int mid=(start+end)/2;
        while(start<=end){
            if(is_k_suitable(piles,h,mid)==true){//with speed of mid, koko can finish all bananas in h hours
                if(mid==1 || is_k_suitable(piles,h,mid-1)==false){
                    //if the k previous to mid is not sutible, mid is the min speed
                    break;
                }
                    //if the k previous to mid is still sutible, mid is not the min speed
                    //we discard the higher part as those are speed that can make koko finish the bananas
                    end = mid-1;
                    mid=(start+end)/2;
                }else{
                    start = mid+1;
                    mid=(start+end)/2;
                }
            }
             return mid;
        }
};
