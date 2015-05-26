/*
 * Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation).
 * Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ).
 * Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like
 * a*b*c).
 *
 * Input
 *
 * t [the number of expressions <= 100]
 * expression [length <= 400]
 * [other expressions]
 * Text grouped in [ ] does not appear in the input file.
 *
 * Output
 *
 * The expressions in RPN form, one per line.
 * Example
 *
 * Input:
 * 3
 * (a+(b*c))
 * ((a+b)*(z+x))
 * ((a+t)*((b+(a+c))^(c+d)))
 *
 * Output:
 * abc*+
 * ab+zx+*
 * at+bac++cd+^*
 */
#include <iostream>
#include <string>
#include <stringstream>
#include <stack>
#include <map>

using namespace std;
#define MAX_NODES 400

struct node_t {
    struct node_t *left;
    struct node_t *right;
    char val;
} typedef Node;


Node* convert_str(string s)
{
    Node *tree = malloc(sizeofo(Node));
    if (strlen(s) == 0)
        return NULL;

    if (strlen(s) == 1)
    {
        if(s[0] != '(' || s[0] != ')') {
            tree->left = NULL;
            tree->right = NULL;
            tree->val = s[0];
            return tree;
        }
    }

    stringstream ss;
    for (int i = 0; i < s.len(); i++) {
        char c = s[i];
        if(c == '(') {
            char* d = strrchr(s, ')');
            string temp = s.substr(i+1, d-s-i-1);
            convert_str(temp);
        } else if (isalpha(c)) {
            (string(1,c));
        } 


        }

    }
}

int main()
{
    int n;
    cin >> n;
    while (n > 0) {
        string s;
        cin >> s;
        cout << convert_str(s) << endl;
        n--;
    }
}

