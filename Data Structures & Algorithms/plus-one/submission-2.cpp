class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int carry=1;
        int n=digits.size();
        int i=0;
        reverse(digits.begin(),digits.end());
        while(i<n || carry){
              int d = (i < n) ? digits[i] : 0;
            ans.push_back((d+carry)%10);
            carry=(d+carry)/10;
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
