class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //using stack 
        int n=heights.size();
        //crate two vector which will store left and right small values  having same size
        vector<int>left(n);
        vector<int>right(n);
        //fill right vector with small values 
        stack<int>st; // will store small values  at its top
        for(int i=n-1;i>=0;i--){
            //if stack have big value from incoming value
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            //insert value in right array and insert in right array 
            right[i]= st.empty()?n:st.top(); //if st is empty then enter n becour right value if aleways smal for itself 

              //insert index in stack 
              st.push(i);
        }
        //empty stack if it have someti9ng 
        while(!st.empty()){
            st.pop();
        }

        //fill left array with small values 
        for(int i=0;i<n;i++){
            //remove top of the stack  if have big value 
            while( !st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            //now stack have small value on its top 
            left[i]= st.empty()?-1:st.top();//if sttack is empty then enter -1
            //insert value in satck 
            st.push(i);
        }


        //pick each value of both vectors and then calculate area 
        int area=0;
        int maxarea=0;
        for(int i=0;i<n;i++){
            int width=abs(right[i]-left[i]-1);
            area=width*heights[i];
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};
