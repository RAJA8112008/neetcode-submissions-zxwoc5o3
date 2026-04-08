class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto val:mp){
            if(val.second>=2){
                return val.first;
            }
        }
        return -1;
    }
};
