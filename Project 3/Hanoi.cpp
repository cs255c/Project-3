/* Towers of Hanoi done recursively
 * When Hanoi function is called, it calls itself with 1 fewer disk,
 * until a single disk remains to be moved. In the process, the start, hold,
 * and end pegs switch roles temporarily, ending where they began.
 * Alex Debrecht */

#include <iostream>
using namespace std;

// Recursive Hanoi function - move n-1 disks until n = 1
void hanoi(int diskNum, int start, int end, int hold) {
	// Base case - move the last (smallest) disk to the top of the stack
	if (diskNum == 1) {
		cout << start << " → " << end << endl;
	// Move n-1 disks to holding peg, move largest disk to end peg, then move n-1 disks to end peg
	} else {
		hanoi(diskNum - 1, start, hold, end);
		cout << start << " → " << end << endl;
		hanoi(diskNum - 1, hold, end, start);
	}
}

// Determine holding peg given start and end
int tempPeg(int start, int end) {

	if ((start == 2 && end == 3) || (start == 3 && end == 2)) {
		return 1;
	} else if ((start == 1 && end == 3) || (start == 3 && end == 1)) {
		return 2;
	} else if ((start == 2 && end == 1) || (start == 1 && end == 2)) {
		return 3;
	}

	return 0;

}

// function main begins program execution
int main() {

	// Declare variables
	int diskNum;
	int start;
	int end;
	int temp;

	// Ask user for number of disks, start, and end peg
	cout << "Enter the number of disks to move." << endl;
	cin >> diskNum;
	cout << "Enter the starting peg." << endl;
	cin >> start;
	cout << "Enter the ending peg." << endl;
	cin >> end;

	temp = tempPeg(start, end); // Determine temporary peg

	hanoi(diskNum, start, end, temp); // Call first Hanoi movement (recursive)

}
