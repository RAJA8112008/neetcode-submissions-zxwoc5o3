class Solution {
public:
  bool iseat(vector<int>& piles, int h,int mid){
    int eattime=0;
      for(auto p:piles){
        eattime += p/mid;
        if(p%mid!=0){
            eattime++;
        }
      }
      return eattime<=h;
  }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
       int right = *max_element(piles.begin(), piles.end());
       while(left<right){
        int mid=left+(right-left)/2;
        //get check koko eats in given time or not
        if(iseat(piles,h,mid)){
            right=mid;
        }else{
            left=mid+1;
        }
       }
       return left;
    }
};
