class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
pair<int,int> pointers = {-1,-1};
        unordered_map<char,int> mt;
        for(int i=0;i<t.length();i++){
            mt[t[i]]++;
        }
        int lp;
        for(lp=0;lp<t.length();lp++){
            if(mt.find(s[lp]) != mt.end()) break;
        }
        int rp=lp;
        for(int i=lp;i<=s.length();i++){
            unordered_map<char,int> m = mt;
            int j = i;
        while(m.size()){
if(j==s.length()) {
    if(pointers==pair<int,int>{-1,-1}) return "";
    else
    return s.substr(pointers.first,pointers.second-pointers.first);
}
            if(m.find(s[j]) != m.end()){
                if(m[s[j]]==1) m.erase(s[j]);
                else {
                    m[s[j]]--;
                }
            }
            j++;

        }
cout<<pointers.first<<" "<<pointers.second<<" i "<<i<<" j "<<j<<" ";
        if(pointers == pair<int,int>{-1,-1} || j-i<pointers.second-pointers.first){
            pointers.first = i;
            pointers.second = j;
        }

        }
        cout<<"YO";
        if(pointers==pair<int,int>{-1,-1}) return "";
        else return s.substr(pointers.first,pointers.second-pointers.first);
    }
};
