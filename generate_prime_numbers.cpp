/*
 *  Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to
 *  generate all prime numbers between two given numbers!
 *  Input
 *
 *  The input begins with the number t of test cases in a single line (t<=10). In each of the next t
 *  lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a
 *  space.
 *  Output
 *
 *  For every test case print all prime numbers p such that m <= p <= n, one number per line, test
 *  cases separated by an empty line.
 *  Example
 *
 *  Input:
 *  2
 *  1 10
 *  3 5
 *
 *  Output:
 *  2
 *  3
 *  5
 *  7
 *
 *  3
 *  5
 *
 *  Warning: large Input/Output data, be careful with certain languages (though most should be OK if
 *  the algorithm is well designed)
 */

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;

#define MAX 1000000000

vector<int> build_prime_factors (int m) {
    vector<int> out;
    int n = sqrt(m) + 1;
    out.push_back(2);

    for (int i = 3; i <= n; i+=2) {
        bool isprime = true;
        int cap = sqrt(i) + 1;

        vector<int>::iterator p;
        for (p = out.begin(); p != out.end(); p++) {
            if (*p >= cap) break;
            if (i % *p == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) out.push_back(i);
    }
    return out;
}

int main()
{
    vector<int> pf = build_prime_factors(MAX);
    int n,p,q;
    cin >> n;
    while (n > 0) {
        cin >> p >> q;
        if (p == 1)
            p = 2;
        for (int i = p; i <= q; i++)
        {
           bool prime = true;
           for (int j = 0; j < pf.size(); j++) {
                if (i%pf[j] == 0 && i != pf[j]) {
                    prime = false;
                    break;
                }
                if (pf[j] > sqrt(i)) {
                    break;
                }
           } 
           if (prime) {
            cout << i << endl;
           }
        } 
        cout <<endl;
        n--;
    }
}
