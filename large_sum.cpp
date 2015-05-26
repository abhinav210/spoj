#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string sum(string a, string b) {
    int len_a = a.size();
    int len_b = b.size();
    int carry = 0;
    int i = 0;

    if (len_a == 0)
        return b;
    if (len_b == 0)
        return a;
    int len_s = max(len_a,len_b) + 1;
    string s = string(len_s, '0');

    for (i = 0; i < len_s; i++) {
        int first = 0;
        if (i < len_a) 
        {
            first = a[len_a-1 - i]-'0';
        }
        int second = 0;
        if (i < len_b)
        {
            second = b[len_b-1 - i]-'0';
        }
        int sum = first+second+carry;
        carry = sum/10;
        sum = sum%10;
        s[len_s-1 - i] = sum+'0';
    }

    i = 0;
    while(i != len_s && s[i++] == '0') {
    }

    return s.substr(i-1, string::npos);
}

#if 0
int main() {
    string a,b;
    cout << sum(string("45"), string("")) << endl;
    cout << sum(string("45"), string("56")) << endl;
    cout << sum(string("0"), string("0")) << endl;
    cout << sum(string("5676"), string("0")) << endl;
    cout << sum(string("334592342342349234923423423453454353534534534535676"), string("4564564564645645654645645645645646460")) << endl;
    return 0;
}
#endif
