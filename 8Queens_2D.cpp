// 8Queens_2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main() {
    int q[8][8] = {};
    int r = 0, c = 0;
    q[r][c] = 1;
    int sln = 0; // solution number
NC:    c++;
    if (c == 8) goto print;
    r = -1; // start at the top
NR:
    r++;
    if (r == 8) goto backtrack;

    // testing if position q[r][c] is ok to place a queen

    // same row test

    for (int i = 0; i < c; i++) {
        if (q[r][i] == 1) goto NR;
    }

    // upper-left diagonal test

    for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++) {
        if (q[r - i][c - i] == 1) goto NR;
    }

    // lower-left diagonal test

    for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++) {
        if (q[r + i][c - i] == 1) goto NR;
    }

    q[r][c] = 1;
    goto NC;
backtrack:
    c--;
    if (c < 0) return 0; // terminate this program
    r = 0;
    while (q[r][c] != 1) r++;
    q[r][c] = 0;
    goto NR;
print:
    // TODO: print the solution
    cout << "Solution #" << ++sln << ":\n";
    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            cout << q[i][k];
        }
        cout << "\n";
    }
    cout << "\n";
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
