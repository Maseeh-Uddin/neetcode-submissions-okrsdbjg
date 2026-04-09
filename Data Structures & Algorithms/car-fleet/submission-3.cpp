class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> detail;
        for(int i=0;i<speed.size();i++){
            detail.emplace_back(pair<int,int>{position[i],speed[i]});
        }

        sort(detail.begin(),detail.end(),[](pair<int,int> a,pair<int,int> b){
            return a.first > b.first;
        });
int ans=1;
        pair<int,int> curr = detail[0];
        for(int i=1;i<detail.size();i++){
            //cout<<detail.size();
            cout<<detail[i].first<<" "<<detail[i].second<<endl;
            //if(i==3) return ans;
            if((double)((target-detail[i].first)*curr.second) <= (double)((target-curr.first)*detail[i].second)){
                continue;
            }
            else{
                curr = detail[i];
                ans++;
            }
        }
        return ans;
    }
};
