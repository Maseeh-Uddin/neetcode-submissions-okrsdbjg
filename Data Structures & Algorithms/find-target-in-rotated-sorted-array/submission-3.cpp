class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int mid = left + (right-left)/2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        int st = left;
        cout<<st;
left = 0;
    right = st-1;
    while(right>=0 && left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target){
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }

        left = st;
        right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            cout<<left<<right<<mid;
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target){
                
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
    return -1;
    }
    
};
