class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> freq;
        int i = 0;
        int curr = nums[0];
        freq.emplace_back(curr,1);
        for(auto it = nums.begin()+1; it!=nums.end();++it){
            if(*it == curr){
                freq[i].second++;
            }
            else{
                freq.emplace_back(*it,1);
                curr=*it;
                i++;
            }
        }

        sort(freq.begin(), freq.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        vector<int> ans;
        for(int j=0;j<k;j++){
            ans.emplace_back(freq[j].first);
        }
        return ans;
    }
};
