class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char top = '0';
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){//add elemnt
                st.push(s[i]);
            }
            else{//remove
                if(st.empty() == true){
                    return false;
                }
                top = st.top();
                if(top == '[' && s[i] == ']'){
                    st.pop();
                }
                else if(top == '{' && s[i] == '}'){
                    st.pop();
                }
                else if(top == '(' && s[i] == ')'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty() == true ){
            return true;
        }
        return false;
    }
};