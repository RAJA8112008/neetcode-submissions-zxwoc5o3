class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //create set and remove duplicate values ansd insert values 
        set<int>s(nums.begin(),nums.end());//insert values in set 
        //copy set in another vector and sort them 
        vector<int>arr(s.begin(),s.end());
        //consecuive sequence 
        int count=1;//each value have its own count
        int maxcount=0;//it will  store largest sequence count  
        for(int i=0;i<arr.size();i++){
            if(arr[i+1]-arr[i]==1){
                count++;
            }else{
                //if differnce is not 1 then get upcoming largest sequesnce 
                //and store it in variable 
                maxcount =max(maxcount,count);
                //reinitilize count 1
                count=1;
            }
        }
     return maxcount;
    }
};
