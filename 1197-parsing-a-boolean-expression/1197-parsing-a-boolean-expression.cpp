/*Intuition and approach
create stack of char and traverse throw the expression string and do below :- expression ==> (!(&('t', 'f', 't')))

step1 :- if current Char ch = '(' or ',' ==> continue
step2 :- if char ch = any operator(&, !, |) ==> push to stack
step3 :- if char ch = ')' ==> we should now eval expression.

so in this step we will keep on poping out the elements ('t', 'f')
untill we get any operator on the top of stack.

while st.peek()!=operator(&, !, |) ===>
we can have 2 boolean variable ==> hasT = false , hasF = false initially

in while loop keep on pop out , if we found 't' ==> hasT = true
if we found 'f' ==> hasF = true

once we come out of while loop ===> now on top of stack there should be one of the operator ==>

if op = ! ==> if(hasT == true) ==> st.push('f')
===> else st.push('t')

if op = & ==> if(hasT == true && hasF=false) ==> st.push('t')
===> else st.push('f')
why?? ==> because hasT = true and hasF = false ==> all are 't' only otherwise mixed so ==> false

if op = | ==> if(hasT == true) ==> st.push('t')
===> else st.push('f')

now keep on repeating this till string ends...finally top of stack if 't' return true otherwise false.
*/
class Solution {
public:
    bool parseBoolExpr(const std::string& expression) {
        std::stack<char> st;
        char temp = ' ', op = ' ';

        for (char ch : expression) {
            if (ch == '(' || ch == ',')
                continue;

            if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|')
                st.push(ch); 
            else if (ch == ')') {

                bool hasTrue = false, hasFalse = false;

 
                while (!st.empty() && st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') hasTrue = true;
                    if (val == 'f') hasFalse = true;
                }

                if (!st.empty())
                    op = st.top(), st.pop(); 


                if (op == '!') {
                    temp = hasTrue ? 'f' : 't';
                } else if (op == '&') {
                    temp = (hasTrue && !hasFalse) ? 't' : 'f';
                } else if (op == '|') {
                    temp = hasTrue ? 't' : 'f';
                }
                st.push(temp);
            }
        }
        return st.top() == 't';
    }
};