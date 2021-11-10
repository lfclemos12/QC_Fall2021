// Stable_Marriage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
using namespace std;

bool ok(int q[], int col) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences

	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences

	/*Similar to 1D Queens, use a loop to check the array.
	  Inside the loop we chould check for 3 conditions
	  First condition checks is the same women is married to two different man *hint we need to check if two things are equal*
	  Second condition checks if (Man#i) and (Man#c's wife) both like each other more than their own spouse
	  Third condition checks if (Man#c) and (Man#i's wife) both like each other more than their own spouse

	  mp[i][j] tells you how much Man#i likes Woman#j. (0 = favorite; 2 = least favorite)
	  wp[i][j] tells you how much Woman#i likes Man#j.

	  mp[i][q[i]] tells you how much Man#i likes his own wife.
	  mp[i][q[c]] tells you how much Man#i likes Man#c's wife.
	  wp[q[i]][i] tells you how much Man#i's wife likes Man#i.
	  wp[q[i]][c] tells you how much Man#i's wife likes Man#c.
	  If mp[i][q[c]] < mp[i][q[i]], it means that Man#i likes Man#c's wife more than his own wife
	*/

	//if we pass the loop, what do we return?

	for (int i = 0; i < col; i++) {
		if (q[i] == q[col] || // checks if wife was repeated
			(mp[i][q[i]] > mp[i][q[col]] && wp[q[col]][col] > wp[q[col]][i]) || 
			(mp[col][q[col]] > mp[col][q[i]] && wp[q[i]][i] > wp[q[i]][col]))
			return false;
	}

	return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	//Finish this print function
	for (int i = 0; i < 3; i++) {
		cout << "\n" << i << "\t" << q[i] << "\n";
	}
	cout << endl;
}


int main() {
	//Write the main function.
	//The main function is exactly the same as 1D Queens. EXCEPT the array size is different.
	int q[3], c = 0;
	q[0] = 0;

	while (c >= 0) {
		c++; // View next man
		if (c == 3) { // if passed the last man -> sol'n found
			print(q); // call the print function and backtrack
			c--;
		}
		else q[c] = -1; // move to one before the first woman
		while (c >= 0) {
			q[c]++; // View next woman
			if (q[c] == 3) c--; // if passed all women -> backtrack one column
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
