class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;
        int i=0;
        while(true){
            if (isdigit(tokens[i][0]) || 
   (tokens[i].size() > 1 && tokens[i][0] == '-')){
            cout<<i;
                s.push(stoi(tokens[i]));
            }
            else{
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
cout<<op1<<" "<<op2;
                if(tokens[i]=="+"){
                    s.push(op1+op2);
                }
                else if(tokens[i]=="-"){
                    s.push(op1-op2);
                }
                else if(tokens[i]=="*"){
                    s.push(op1*op2);
                }
                else if(tokens[i]=="/"){
                    s.push(op1/op2);
                }
            }
            i++;
            if(i==tokens.size()){
                return s.top();
            }
        }
        
        // int curr=stoi(tokens[0]);
        // int i =1;
        // while(i<tokens.size()-1){
        //     cout<<i;
        //     if(tokens[i+1]=="+"){
        //         curr = curr + stoi(tokens[i]);
        //         cout<<curr<<" ";
                
        //     }
        //     else if(tokens[i+1]=="-"){
        //         curr = curr - stoi(tokens[i]);
                
        //     }
        //     else if(tokens[i+1]=="*"){
        //         curr = curr * stoi(tokens[i]);
        //     }
        //     else if(tokens[i+1]=="/"){
        //         curr = curr/stoi(tokens[i]);
        //     }
        //         i = i+2;

        // }
        // return curr;
    }
};
