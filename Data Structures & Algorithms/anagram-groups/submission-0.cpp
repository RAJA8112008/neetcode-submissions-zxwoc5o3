class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
       vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string smp=strs[i];
            sort(smp.begin(),smp.end());
            mp[smp].push_back(strs[i]);
        }
        for(auto val:mp){
            ans.push_back(val.second);
        }
        return ans;
    }
};
