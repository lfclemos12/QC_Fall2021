// 8Queens_1D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int q[8], c = 0;
    q[0] = 0;

NC: c++;
    if (c == 8) goto print;
    q[c] = -1;
NR: q[c]++;
    if (q[c] == 8) goto backtrack;
    
    // Combined Test
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || (c - i) == abs(q[c] - q[i])) goto NR;
    }
    goto NC;
backtrack: c--;
    if (c == -1) return 0;
    goto NR;
print:
    static int sln = 0; // solution number
    cout << "Solution #" << ++sln << ":\n";
    for (int r = 0; r < 8; r++) {
        for (int i = 0; i < 8; i++) {
            if (q[i] == r) cout << '1';
            else cout << '0';
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
