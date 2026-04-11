class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //sort(piles.begin(),piles.end());

        //return piles[piles.size()-1]/(h/piles.size());
        int maxVal = 0;

        for(int x: piles){
            maxVal = max(maxVal,x);
        }
        int left = 1;
        int right = maxVal;
        int ans = maxVal;
        while(left<=right){
            int mid = left + (right-left)/2;
            int midTime = calcTime(piles,h,mid);
            if(midTime > h){
               left = mid+1;
            }
            else{
                ans = min(ans,mid);
                right = mid-1;
            }

        }
        return ans;
    }
    int calcTime(vector<int> &piles, int h,int k){
        int ans = 0;
        for(int x: piles){
            ans += (x%k==0? x/k : 1+(x/k) );
        }
        return ans;
    }
};
