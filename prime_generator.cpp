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
#include <map>
#include <stdlib.h>
using namespace std;

#if 0
#define MAX 1000000000
#define SIZE_ARR (MAX/sizeof(char) + 1)
char arr[SIZE_ARR] = {0,};

void set_i(int i)
{
    div_t divresult = div(i, sizeof(char));
    int idx = divresult.quot;
    int bit = divresult.rem;
    arr[idx] = arr[idx] | (1<<bit);
    //cout << "set idx: " << idx << " bit: " << bit << " i:" << i << endl;
}

bool if_prime_i(int i)
{
    div_t divresult = div(i, sizeof(char));
    int idx = divresult.quot;
    int bit = divresult.rem;
    //cout << "idx: " << idx << " bit: " << bit << " i:" << i << endl;
    return (arr[idx] & (1<<bit)) == 0;
}

void build_primes()
{
    set_i(1);
    for(int i = 2; i < sqrt(MAX); i++)
    {
        if(if_prime_i(i)){
            for(int j = i; j*i <= MAX; j++)
            {
                set_i(i*j);
            }
        }
    }
}
#endif

#define MAX 100000
#define SIZE_ARR MAX
int LOWER = 0;
char arr[SIZE_ARR] = {0,};
void inline set_i(int i)    { arr[i-LOWER]=1; }
bool inline if_prime_i(int i) { return (arr[i-LOWER] == 0); }
void build_primes(int p, int q)
{
    set_i(1);
    for(int i = p; i <= q; i++)
    {
        if(if_prime_i(i))
        {
            for (int j = 2; j <=i/2; j++)
            {
                if (i%j == 0)
                {
                    set_i(i);
                    for(int k = i; k <= q/i; k++)
                    {
                        set_i(i*k);
                    }
                    break;
                }
                //test division with only odd values
                if (j != 2) {
                    j++;
                }
            }
        }
    }
    for(int i = p; i <= q; i++)
    {
        if(if_prime_i(i))
        {
            cout << i << endl;
        }
    }
}
void print_primes_from_built_primes(int p,int q)
{
    for (int i = p; i <= q; i++) {
        if (if_prime_i(i))
        {
            cout <<i<<endl;
        }
    }
}

void print_primes(int p, int q)
{
    for (int i = p; i <= q; i++)
    {
        int flag = 0;
        for (int j = 2; j <=i/2; j++)
        {
            if (i%j == 0)
            {
                flag = 1;
                break;
            }
            //test division with only odd values
            if (j != 2) {
                j++;
            }
        }
        if (flag == 0)
            if (i != 1)
                cout << i << endl;
    }
}
int main()
{
    int n,p,q;
    cin >> n;
    //build_primes();
    while (n > 0) {
        cin >> p >> q;
        LOWER = p;
        build_primes(p,q);
        cout <<endl;
        n--;
    }

}
