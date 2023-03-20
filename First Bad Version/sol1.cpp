// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {//do an adpated binary search
        int64_t start = 1;
        int64_t end = n;
        int64_t mid = (start+end)/2;
        //we know that ach version is developed based on the previous version,
        // all the versions after a bad version are also bad
        while(start<=end){
            if(isBadVersion(mid)==true){
                if(isBadVersion(mid-1)==false){
                    break;
                }
                //discard higher part, everything after the mid are defective
                end = mid-1;
                mid = (start+end)/2;
            }else{//discard lower part, everything before the mid are not defective
                start = mid+1;
                mid = (start+end)/2;
            }
        }
        return mid;
    }
};