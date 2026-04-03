class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        int nonZeroCount = 0;
        int nonZeroP = 1;
        for(int x: nums){
            if(x==0){
                nonZeroCount ++;
            }
            else nonZeroP *= x;
            p *= x;
        }
        if(nonZeroCount > 1) return vector<int> (nums.size(), 0);
        vector<int>ans;
        ans.reserve(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) ans.emplace_back(nonZeroP);
            else
            ans.emplace_back(p/nums[i]);
        }
        return ans;
    }
};
