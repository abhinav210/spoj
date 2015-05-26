#include "large_sum.cpp" 
#include <assert.h>
using namespace std;

string ten_fold(string a)
{
    return a + '0';
}

string mult_easy(string a, string b)
{
    int a_len = a.size();
    int b_len = b.size();
    int s_len = max(a_len, b_len) + 1;
    string x,y;
    int y_len = 0;
    int i = 0;
    string s = string(s_len, '0');

    assert(a_len == 1 || b_len == 1);

    if (a_len == 1)
    {
        x = a;
        y = b;
        y_len = b_len;
    }
    else
    {
        x = b;
        y = a;
        y_len = a_len;
    }
    //x is the single digit number
    int carry = 0;
    for (i = 0; i < s_len; i++) {
        int first = 0;
        if (i < y_len) 
        {
            first = y[y_len-1 - i]-'0';
        }
        int second = x[0] - '0';
        int mult = (first*second)+carry;
        carry = mult/10;
        mult = mult%10;
        s[s_len-1 - i] = mult+'0';
    }
    i = 0;
    while(i != s_len && s[i++] == '0') {
    }

    return s.substr(i-1, string::npos);
}

string mult(string a, string b) 
{
    string s("0");
    int a_len = a.size();
    int b_len = b.size();
    if (a_len == 0 || b_len == 0)
        return string("0");
    if (a_len == 1 || b_len == 1)
        return mult_easy(a,b);

    for (int i = 0; i < a_len; i++) {
        string temp = mult(b, a.substr(i, 1));
        for (int j = 0; j < a_len - i - 1; j++)
        {
            temp = ten_fold(temp);
        }
        s = sum(s,temp);
    }
    return s;
}

int main() {
    string a,b;
    cin>>a;
    cin>>b;
    string s = sum(a,b);
    string m = mult(a,b);
    cout << endl << s << endl;
    cout << endl << m << endl;
    cout << endl << ten_fold(m) << endl;
    return 0;
}
