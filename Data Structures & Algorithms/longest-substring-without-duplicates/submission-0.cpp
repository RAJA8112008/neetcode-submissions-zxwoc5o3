class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int left=0;
      int maxLen=0;
      unordered_map<char,int>mp;
      for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(mp.find(ch)!=mp.end()){
            //arrange left  to the right window
            left=max(left,mp[ch]+1);
        }
        //insert in map
        maxLen=max(maxLen,i-left+1);
        mp[ch]=i;
      }
      return maxLen;
    }
};
