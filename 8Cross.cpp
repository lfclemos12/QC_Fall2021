// 8Cross.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void print(int cross[]){
    static int count = 0;
    cout << " Solution #" << ++count << endl;
    cout << " " << cross[1] << cross[2] << endl;
    cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
    cout << " " << cross[6] << cross[7] << "\n" << endl;
    return;
}

bool ok(int cross[], int c) {
    static int helper[8][5] = {
        {-1},
        {0,-1},
        {1,-1},
        {0,1,2,-1},
        {1,2,3,-1},
        {2,4,-1},
        {0,3,4,-1},
        {3,4,5,6,-1},
    };

    for (int i = 0; i < c; i++) {
        if (cross[i] == cross[c]) return false;
    }

    for (int i = 0; helper[c][i] != -1; i++) {
        if (abs(cross[c] - cross[helper[c][i]]) == 1) return false;
    }

    return true;
}

int main()
{
    int q[8], c = 0;
    q[0] = 1;

    while (c >= 0) {
        c++; // Move to the next square
        if (c == 8) { // if passed the last square -> sol'n found
            print(q); // call the print function and backtrack
            c--;
        }
        else q[c] = 0; // Start before the first consecutive number
        while (c >= 0) {
            q[c]++; // Try next number
            if (q[c] == 9) c--; // if tried all numbers -> backtrack one square
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
