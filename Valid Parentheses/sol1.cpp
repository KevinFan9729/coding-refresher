class Solution {
public:
    bool isValid(string s) {
        vector<char>check;
        for(int i = 0; i < s.size(); i++){
            //insert
            if(s[i]=='('){
                check.push_back('(');
                continue;
            }else if(s[i]=='['){
                check.push_back('[');
                continue;
            }else if(s[i]=='{'){
                check.push_back('{');
                continue;
            }
            //remove
            if(s[i]==')'){
                if(check.size()<=0){
                    return false;
                }
                if(check.back()=='('){
                    check.pop_back();
                    continue;
                }else{
                    return false;
                }
            }else if(s[i]==']'){
                if(check.size()<=0){
                    return false;
                }
                if(check.back()=='['){
                    check.pop_back();
                    continue;
                }else{
                    return false;
                }
            }else if(s[i]=='}'){
                if(check.size()<=0){
                    return false;
                }
                if(check.back()=='{'){
                    check.pop_back();
                    continue;
                }else{
                    return false;
                }
            }
        }
        if(check.size()==0){
            return true;
        }
        return false;
    }
};