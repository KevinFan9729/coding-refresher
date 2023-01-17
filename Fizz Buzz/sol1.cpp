
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> ans(n);
        for(int i =0; i<n; i++){
            int temp = i+1;
            if((temp%3)==0 and (temp%5)==0){ //and is equivalent to &&
                ans[i] = "FizzBuzz";
            } else if ((temp%3)==0){
                ans[i] = "Fizz";
            } else if((temp%5)==0){
                ans[i] = "Buzz";
            }else{
                ans[i] = std::to_string(temp);
            }
        }
        return ans;
    }
};
