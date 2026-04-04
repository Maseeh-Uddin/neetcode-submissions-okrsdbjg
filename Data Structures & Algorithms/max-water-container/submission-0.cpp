class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int i = 0;
        int j = heights.size()-1;
        int currMax = 0;
        while(i<j){
            currMax = (j-i)*min(heights[j],heights[i]);
            if(currMax>ans){
                ans = currMax;
            }
            heights[i]<heights[j] ? i++ : j--;
        }
        return ans;
    }
};
