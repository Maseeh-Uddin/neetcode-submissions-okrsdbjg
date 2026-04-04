class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i<nums.size()-2;i++){
cout<<nums[i]<<" ";
            if(i>0&&nums[i] == nums[i-1]) continue;
            vector<pair<int,int>> res = twoSum(nums,i,(-1)*nums[i]);
            if(res.size()){
                for(pair<int,int> x: res){
                    ans.emplace_back(vector<int>{nums[i],x.first, x.second});
                }
            }
        }
        return ans;
    }
    vector<pair<int,int>> twoSum(vector<int>& nums, int start, int target){
        int i = start + 1;
        int j = nums.size()-1;
int curr;
vector<pair<int,int>> ans;
        while(i<j){
            curr = nums[i] + nums[j];
            if(curr==target) {cout<<nums[i]<<" "<<nums[j]<<" ";ans.emplace_back(pair<int,int>{nums[i],nums[j]});
            do{i++;}
                    while(nums[i]==nums[i-1]);
                     do{j--;}
                    while(nums[j]==nums[j+1]);
                    cout<<"hi "<< nums[i]<<" "<<nums[j]<<" ";
            }
            else{
                if(curr<target){
                    i++;
                    
                }
                else{
                   j--;
                }
            }
        }
        return ans;
    }
};
