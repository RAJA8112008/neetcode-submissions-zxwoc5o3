class Solution {
public:

    string encode(vector<string>& strs) {
     string s="";
      for(int i=0;i<strs.size();i++){
        int size=strs[i].size();
        s+=to_string(size)+"#"+strs[i];
      }
      return s;
    }
    vector<string> decode(string s) {
      vector<string>ans;
      for(int i=0;i<s.size();){
        int j=i;
        //getting length
        while(s[j]!='#'){
            j++;
        }
        int len=stoi(s.substr(i,j-i));
        //find word
        string word=s.substr(j+1,len);
        ans.push_back(word);
        //update i 
        i=j+1+len;
      }
      return ans;
    } 
};
