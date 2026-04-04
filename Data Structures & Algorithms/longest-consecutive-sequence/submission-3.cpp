class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> s;

        int ans=1;
        for(int x:nums){
            s.insert(x);
        }
        for(int x: s){
            int curr = 0;
            if(s.count(x+1) && !s.count(x-1)){
                curr = 0;
                cout<<x;
                for(int i =x; s.count(i);i++){
                    curr++;
                }
                if(curr > ans) ans = curr;
            }
        }
        return ans;
    }
};
