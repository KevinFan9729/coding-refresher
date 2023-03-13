
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *                1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);
class Solution {
public:
    int64_t guessNumber(int64_t n) {
        int64_t mid = (n+1)/2;
        int64_t start=1;
        int64_t end=n;
        // mid=start+(end-start)/2;
        while(start<=end){
            if (guess(mid)<0){//your guess is higher than the number, we will discard the higher range
                end = mid-1;
            }else if(guess(mid)>0){//your guess is lower than the number, we will discard the lower range
                start = mid+1;
            }else{
                return mid;
            }
            mid = (start+end)/2;
        }
        return -1;
    }
};
