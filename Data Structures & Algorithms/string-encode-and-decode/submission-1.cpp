class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(string s: strs){
            ans.append(to_string(s.length()) + "$");
            ans.append(s);
        }
        //cout<<ans<<" ";
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i=0;i<s.length();i++){
            //cout<<s[i]<<" ";
            string lenStr = "";
            while(isdigit(s[i])) {lenStr.push_back(s[i]); i++;}
            //cout<<lenStr<<" ";
            int len = stoi(lenStr);
           // cout<<len<<" ";
            //cout<<s.substr(i+1)<<" ";
            ans.emplace_back(s.substr(i+1,len));
           // cout<<ans[0]<<" ";
            i = i  + len;
            //cout<<i<<" ";
        }
        return ans;
    }
};
