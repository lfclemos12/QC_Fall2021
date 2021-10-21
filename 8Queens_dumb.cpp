// 8Queens_dumb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool ok(int q[], int len) {
    int c = len;

    while (c > 0) {
        for (int i = 0; i < c; i++) {
            if (q[i] == q[c] || (c - i) == abs(q[c] - q[i])) return false;
        }
        c--;
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

int main() {
    int q[8];
    for (int i0 = 0; i0 < 8; i0++) {
        for (int i1 = 0; i1 < 8; i1++) {
            for (int i2 = 0; i2 < 8; i2++) {
                for (int i3 = 0; i3 < 8; i3++) {
                    for (int i4 = 0; i4 < 8; i4++) {
                        for (int i5 = 0; i5 < 8; i5++) {
                            for (int i6 = 0; i6 < 8; i6++) {
                                for (int i7 = 0; i7 < 8; i7++) {
                                    q[0] = i0;
                                    q[1] = i1;
                                    q[2] = i2;
                                    q[3] = i3;
                                    q[4] = i4;
                                    q[5] = i5;
                                    q[6] = i6;
                                    q[7] = i7;

                                    if (ok(q, 8)) print(q);
                                }
                            }
                        }
                    }
                }
            }
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
