class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        //store  0 index val 
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int>val=intervals[0];//here we will store each val of intervals one by  one
        for(int i=0;i<n;i++){
            if(val[1]>=intervals[i][0]){
                val[1]=max(val[1],intervals[i][1]); //will insert last max  value in val[1]
            }else{
                ans.push_back(val);//if have not merge property
               val=intervals[i];
            }
        }
        ans.push_back(val);
        return ans;
    }
};
