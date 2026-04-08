class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s[0]=='(' || s[0]=='{' || s[0]=='['){
            st.push(s[0]);
        }
        else return false;
        int i = 1;
        while(i<s.length()){
            cout<<i;
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(s[i]==')'){
                    if(st.top()=='(') st.pop();
                    else return false;
                }
                else if(s[i]=='}'){
                    if(st.top()=='{') st.pop();
                    else return false;
                }
                else if(s[i]==']'){
                    if(st.top()=='[') st.pop();
                    else return false;
                }
            }
                i++;
        }
        if(st.empty()) return true;
        else return false;
    }
};
