class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        pair<int,int> maxi = {nums[0],1};

        int i=0;
        int j=k-1;

        for(int c=i+1;c<k;c++){
            if(nums[c]==maxi.first){
                maxi.second++;
            }
            else if(nums[c] > maxi.first){
                maxi = {nums[c],1};
            }
        }
        vector<int> ans;
ans.emplace_back(maxi.first);
        i++;j++;
        //cout<<i<<j;
        while(j<nums.size()){
            if(nums[j]==maxi.first){
                maxi.second++;
            }
            if(nums[i-1]==maxi.first){
            cout<<"i "<<i<<" j "<<j<<" maxf "<<maxi.first<<" maxs "<<maxi.second;;
                maxi.second--;
                if(maxi.second==0){
                    maxi = {nums[i],1};
                    cout<<"new "<<maxi.first;
                for(int c=i+1;c<=j;c++){
                    if(nums[c]==maxi.first){
                    //cout<<"hi "<<c<<" hi";
                        maxi.second++;
                    }
                    else if(nums[c] > maxi.first){
                        cout<<" c "<<c<<endl;
                        maxi = {nums[c],1};
                    }
                }
                }
            }
            if(nums[j] > maxi.first){
                maxi = {nums[j],1};
            }
            ans.emplace_back(maxi.first);
            i++;j++;
            cout<<endl;
            //if(j==nums.size()) break;
        }
        return ans;
    }
};
