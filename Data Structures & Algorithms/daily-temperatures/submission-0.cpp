class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<pair<int,int>> s;
        vector<int> ans(temps.size());
        for(int i=0;i<temps.size();i++){
            cout<<i;
            
            if(s.empty()){
                s.push(pair<int,int>(temps[i],i));
            }
            
            else{
                if(temps[i]>s.top().first){
                    while(!s.empty()&&temps[i]>s.top().first){
                        ans[s.top().second] = i-s.top().second;
                        s.pop();
                    }
                    s.push(pair<int,int>(temps[i],i));
                }
                else{
                    s.push(pair<int,int>(temps[i],i));
                }
            }
        }
        while(!s.empty()){
            ans[s.top().second] = 0;
            s.pop();
        }
        return ans;
    }
};
