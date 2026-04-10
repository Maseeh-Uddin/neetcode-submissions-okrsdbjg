class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        int curr = (start+end)/2;
        while(start <= end){
            cout<<start<<" "<<end<< " "<<curr<<endl;
            //if(curr==start || curr == end) return target==nums[curr] ? nums[curr] : -1;
            if(nums[curr]==target) return curr;
            else if(target<nums[curr]){
                end = curr -1 ;
            }
            else{

                start = curr + 1;
            }
            curr = (start+end)/2;
        }
        return -1;
    }
};
