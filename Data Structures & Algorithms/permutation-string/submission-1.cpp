class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        int l1 = s1.length();
        int l2 = s2.length();
        if(l1>l2) return false;
        for(int i=0;i<l1;i++){
            m[s1[i]]++;
        }
        unordered_map<char,int> m2 = m;
        for(int sp=0;sp<=l2-l1;sp++){
        for(int i=sp;i<l2;i++){
        cout<<i<<" ";
            
            if(m2.find(s2[i]) != m2.end()){
                if(m2[s2[i]]==1){
                    m2.erase(s2[i]);
                }
                else{
                    m2[s2[i]]--;
                }
            }
            else{
                cout<<"break at"<<i;
                m2 = m;
                break;
            }
            if(m2.size()==0) return true;
            cout<<endl;
        }
        }
        return false;
    }
};
