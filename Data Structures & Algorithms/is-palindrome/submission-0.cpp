class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> st;
        int sz = s.length();
        for(int i=0;i<sz;i++){
            if(isalnum(s[i]))
            {
                cout<<s[i];
            st.push(tolower(s[i]));
            }
        }
        
        int j = 0;
        while(!st.empty()){
           // cout<<st.top();
           if(!isalnum(s[j])){
            j++; continue;
           }
            if(tolower(s[j])==st.top()){
                st.pop();
                j++;
            }
            else{
                
                return false;
            }
        }
        return true;
    }
};
