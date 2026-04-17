class MinStack {
public:
   stack<int>st;
   stack<int>temp;//we will push only small values (for return minval)
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(temp.empty()){
            temp.push(val);//for first val(when temp stack is empty)
        }else{
            temp.push(min(temp.top(),val));//more than one val (small value must be at top)
        }
    }
    
    void pop() {
        //remove top elem from both 
        st.pop();
        temp.pop();
    }
    
    int top() {
        //return top elem 
    return st.top();
    }
    
    int getMin() {
        return temp.top();
    }
};
