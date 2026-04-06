class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>ans;
        for(auto val:mp){
            ans.push_back({val.first,val.second});
        }
            sort(ans.begin(),ans.end(),[](auto a,auto b){
                return a.second >b.second;
            });
            vector<int>temp;
      for(int i=0;i<k;i++){
        temp.push_back(ans[i].first);
      }
return temp;
    }
};
