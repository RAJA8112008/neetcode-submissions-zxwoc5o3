class MinStack {
public:
    stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())return -1;
        return st.top();
    }
    
    int getMin() {
      
       stack<int>temp=st;
       int minval=INT_MAX;
       while(!temp.empty()){
         minval=min(temp.top(),minval);
         temp.pop();
       }
       return minval;
    }
};
