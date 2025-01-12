class Solution {
public:
    bool canBeValid(string s, string l) {
        int n = s.size();
        stack<int> st,stt;
        for(int i = 0;i<n;i++){
            if(l[i] == '0') st.push(i);
            else{
               if(s[i] == ')'){
                  if(st.empty() && stt.empty()) return 0;
                  if(stt.empty()) st.pop();
                  else stt.pop();
               }
               else stt.push(i);
            }
        }
        while(!st.empty() && !stt.empty() && stt.top() < st.top()){
            st.pop(); stt.pop();
        }
        if(!stt.empty()) return 0;
        return (st.size()%2 == 0);
    }
};