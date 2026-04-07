class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(height[i],left[i-1]);
        }
        vector<int>right(n);
        right[n-1]=height[n-1];
        for(int j=n-2;j>=0;j--){
            right[j]=max(right[j+1],height[j]);
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(right[i],left[i])-height[i];
        }
            return water;
    }
};
