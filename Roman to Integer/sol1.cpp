class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='I'){//special cases (subtractions may be involved)
                if(i!=s.length()-1){//make sure we do not exceed the string length, as exceeding the string length may result in undefined behaviours.
                    if(s[i+1]=='V' or s[i+1]=='X'){
                        ans+=-1;
                    }else{
                        ans+=1;
                    }
                }else{
                    ans+=1;
                }
            }else if (s[i]=='X'){
                if(i!=s.length()-1){
                    if(s[i+1]=='L' or s[i+1]=='C'){
                        ans+=-10;
                    }else{
                        ans+=10;
                    }
                }else{
                    ans+=10;
                }
            }else if (s[i]=='C'){
                if(i!=s.length()-1){
                    if(s[i+1]=='D' or s[i+1]=='M'){
                        ans+=-100;
                    }else{
                        ans+=100;
                    }
                }else{
                    ans+=100;
                }
        }else{//regular cases
                if(s[i]=='V'){
                    ans+=5;
                }else if (s[i]=='L'){
                    ans+=50;
                }else if (s[i]=='D'){
                    ans+=500;
                }else{
                    ans+=1000;
                }
            }
        }
    return ans;
    }
};
