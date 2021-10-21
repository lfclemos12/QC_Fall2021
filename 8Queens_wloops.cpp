// 8Queens_wloops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool ok(int q[], int c) {
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || (c - i) == abs(q[c] - q[i])) return false;
    }
    return true;
}

void print(int q[]) {
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
}

int main()
{
    int q[8], c = 0;
    q[0] = 0;

    while (c >= 0) {
        c++; // Move to the next column
        if (c == 8) { // if passed the last column -> sol'n found
            print(q); // call the print function and backtrack
            c--;
        }
        else q[c] = -1; // move to one before the first row
        while (c >= 0) {
            q[c]++; // Move to next row
            if (q[c] == 8) c--; // if passed all rows -> backtrack one column
            else if (ok(q, c)) break;
        }
    }
    return 0;
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
