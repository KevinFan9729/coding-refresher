class Solution {
public:
    int charToInt(char c){
        if (c == 'I'){
            return 1;
        }else if (c == 'V'){
            return 5;
        }else if (c == 'X'){
            return 10;
        }else if (c == 'L'){
            return 50;
        }else if (c == 'C'){
            return 100;
        }else if (c == 'D'){
            return 500;
        }else if (c == 'M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        int str_len = s.length();
        for(int i=1; i<str_len;i++){
            int current = charToInt(s[i-1]);
            int next = charToInt(s[i]);
            if (current<next){
                current = -1*current;
            }
            ans+=current;
        }
        ans+=charToInt(s[str_len-1]);//handle the last character
        return ans;
    }
};
