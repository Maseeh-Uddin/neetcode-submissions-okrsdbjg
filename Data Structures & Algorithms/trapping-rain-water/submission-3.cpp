class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> water(height.size(),0);

        int maxh = height[0];
        int maxi = 0;
        for(int i=1;i<height.size();i++){
            if(height[i]>maxh) {maxh=height[i]; maxi=i;}
        }
        // int i = 0;
        // int j = height.size()-1;

        int currmaxi = height[0];
        int currmaxj = height[height.size()-1];
        for(int i=1;i<maxi;i++){
            if(height[i]<currmaxi){
                cout<<i<<" "<<currmaxi<< " "<< height[i]<<" ";
                water[i] = currmaxi - height[i];
            }
            else if(height[i]>currmaxi){
                currmaxi = height[i];
            }
            cout<<endl;
        }
        cout<<endl;
        for(int j=height.size()-2;j>maxi;j--){
            if(height[j]<currmaxj){
                cout<<j<<" "<<currmaxj<< " "<< height[j]<<" ";
                water[j] = currmaxj - height[j];
            }
            else if(height[j]>currmaxj){
                currmaxj = height[j];
            }
            cout<<endl;
        }
       // cout<<"maxi "<< maxi;
        int ans=0;
        
        for(int x: water){
            cout<<x<<" ";
            ans += x;
        }
        return ans;
    }
};
