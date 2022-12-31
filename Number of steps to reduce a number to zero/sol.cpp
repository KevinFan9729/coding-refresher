class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num!=0){
            if(num%2==0){
                count+=1;
            }else{
                if (num!=1){
                    count+=2;
                }else{//if we are at the final step, i.e. num == 1
                    count+=1;
                }
            }
            num=num/2;
        }
        return count;
        }
    };
