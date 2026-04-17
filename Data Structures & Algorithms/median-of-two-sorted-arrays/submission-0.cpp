class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //first merge both vectors in sorted array
        vector<int>ans;
        int i=0;
        int n=nums1.size();
        int j=0;
        int m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        //enter remaining elements in ans arraya
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }
       
       //find median  according to the length of array
       //for even length
       if(ans.size()%2!=0){
        return double(ans[ans.size()/2]);
       }
       //for odd lengthis

       if(ans.size()%2==0){
        return double(ans[ans.size()/2]+ans[(ans.size()/2)-1])/2;
       }
  // [1,3] [2,4]--> [1,2,3,4]
        return -1;
    }
};
