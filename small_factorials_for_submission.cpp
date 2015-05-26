#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;
string sum(string a,string b) {
 int l_a=a.size();
 int l_b=b.size();
 int carry=0;
 int i=0;

 if (l_a == 0)
  return b;
 if (l_b == 0)
  return a;
 int l_s=max(l_a,l_b) + 1;
 string s=string(l_s, '0');

 for (i=0; i < l_s; i++) {
  int f=0;
  if (i < l_a) 
   f=a[l_a-1-i]-'0';
  int se=0;
  if (i < l_b)
   se=b[l_b-1-i]-'0';
  int sum=f+se+carry;
  carry=sum/10;
  sum=sum%10;
  s[l_s-1 - i]=sum+'0';
 }

 i=0;
 while(i != l_s && s[i++] == '0') {
 }

 return s.substr(i-1, string::npos);
}
string ten_fold(string a)
{
 return a + '0';
}
string mult_easy(string a, string b)
{
 int a_l=a.size();
 int b_l=b.size();
 int s_l=max(a_l, b_l) + 1;
 string x,y;
 int y_l=0;
 int i=0;
 string s=string(s_l, '0');

 if (a_l == 1)
 {
  x=a;
  y=b;
  y_l=b_l;
 }
 else
 {
  x=b;
  y=a;
  y_l=a_l;
 }
 int carry=0;
 for (i=0; i < s_l; i++) {
  int f=0;
  if (i < y_l) 
  {
   f=y[y_l-1 - i]-'0';
  }
  int se=x[0] - '0';
  int mult=(f*se)+carry;
  carry=mult/10;
  mult=mult%10;
  s[s_l-1 - i]=mult+'0';
 }
 i=0;
 while(i != s_l && s[i++] == '0') {
 }

 return s.substr(i-1, string::npos);
}
string mult(string a, string b) 
{
 string s("0");
 int a_l=a.size();
 int b_l=b.size();
 if (a_l == 0 || b_l == 0)
  return string("0");
 if (a_l == 1 || b_l == 1)
  return mult_easy(a,b);

 for (int i=0; i < a_l; i++) {
  string temp=mult(b, a.substr(i, 1));
  for (int j=0; j < a_l - i - 1; j++)
  {
   temp=ten_fold(temp);
  }
  s=sum(s,temp);
 }
 return s;
}
map <int, string> m;
string factorial (int a)
{
 if (m.find(a) == m.end()) {
  stringstream ss;
  ss << a;
  string s=ss.str();
  m[a]=mult(s, factorial(a-1));
 }
 return m[a];
}
int main() {
 int n=0;
 m[0]="1";
 cin >> n;
 while (n > 0) {
  int a=0;
  cin >> a;
  cout << factorial(a) << endl;
  n--;
 }
}
