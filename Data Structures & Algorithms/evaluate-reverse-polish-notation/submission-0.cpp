class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
       //Enter strings in stack while symbol is not coming
       int i=0;
       int n=tokens.size();
       
       while(i<n) {
        if(tokens[i]!="*" && tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/"){
         st.push(stoi(tokens[i]));
         i++;
       }else{
        //remove two top values of stack and apply operation according to its opertapr
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        //check operatior and inset into stack after operation 
        if(tokens[i]=="*"){
            int operation= b * a;
            st.push(operation);
        }
        if(tokens[i]=="+"){
            int operation= b + a;
            st.push(operation);
        }
        if(tokens[i]=="-"){
           int operation= b - a;
            st.push(operation);
        }
        if(tokens[i]=="/"){
          int operation= b / a;
            st.push(operation);
        }
        i++;
       }
    
       }
       return st.top();
    }

};
