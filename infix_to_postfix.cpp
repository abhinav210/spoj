/* 
Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c).

Input

t [the number of expressions <= 100]
expression [length <= 400]
[other expressions]
Text grouped in [ ] does not appear in the input file.

Output

The expressions in RPN form, one per line.
Example

Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool is_operand(char c)
{
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    return false;
}

bool is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

string infix_to_postfix (const string &s)
{
    stack <char> st;
    string out = "";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (is_operator(c)) {
            while (!st.empty() && st.top() != '(') {
                out += st.top();
                st.pop();
            }
            st.push(c);
        } else if (is_operand(c)) {
            out+=c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                out += st.top();
                st.pop();
            }
            st.pop();
        }
    }

    while (!st.empty()) {
        out+=st.top();
        st.pop();
    }
    return out;

}

int main()
{
    unsigned int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << infix_to_postfix(s) << endl;
    }


}
