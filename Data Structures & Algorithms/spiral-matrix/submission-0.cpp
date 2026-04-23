class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int firstrow=0;
        int lastrow=row-1;
        int firstcol=0;
        int lastcol=col-1;
        int totalcount=row*col;
        int count=0;
        vector<int>ans;
        while(count<totalcount){
           //print first row  elements 
           for(int i=firstcol;i<=lastcol && count <totalcount;i++){
            ans.push_back(matrix[firstrow][i]);
            count++;
           }
           firstrow++;
            //print lastcol elements 
            for(int i=firstrow;i<=lastrow  && count <totalcount;i++){
                ans.push_back(matrix[i][lastcol]);
                count++;
            }
            lastcol--;
           
           //print lastrow element in reverse order 
           for(int i=lastcol;i>=firstcol  && count <totalcount;i--){
            ans.push_back(matrix[lastrow][i]);
            count++;
           }
           lastrow--;
           //print all element of first col in reverse  order 
           for(int i=lastrow;i>=firstrow  && count <totalcount;i--){
            ans.push_back(matrix[i][firstcol]);
            count++;
           }
           firstcol++;
        }
    return ans;
    }
};
