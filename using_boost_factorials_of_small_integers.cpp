/*
 * You are asked to calculate factorials of some small positive integers.
 *
 * Input
 *
 * An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a
 * single integer n, 1<=n<=100.
 *
 * Output
 *
 * For each integer n given at input, display a line with the value of n!
 *
 * Example
 *
 * Sample input:
 * 4
 * 1
 * 2
 * 5
 * 3
 * Sample output:
 *
 * 1
 * 2
 * 120
 * 6
 *
 */
#include <iostream>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

map <int, cpp_int> m;
cpp_int factorial (int a)
{
    if (m.find(a) == m.end()) {
        m[a] = a * factorial(a-1);
    }
    return m[a];
}

int main() {
    int n = 0;
    m[0] = 1;
    m[1] = 1;
    cin >> n;
    while (n > 0) {
        int a = 0;
        cin >> a;
        cout << factorial(a) << endl;
        n--;
    }
}
