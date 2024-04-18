#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 12; // Number of rows in the plane
const int COLS = 5;  // Number of seats in each row

// Function prototypes
int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][COLS], int column);

int main() {
    // Initialize the seating chart
    char seats[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            seats[i][j] = 'O';
        }
    }

    // Display initial seating chart
    cout << "Initial seating chart:" << endl;
    for (int col = 0; col < COLS; ++col) {
        cout << "Column " << static_cast<char>('A' + col) << ": ";
        displaySeatColumn(seats, col);
        cout << endl;
    }

    // Looping the seat reservation
    int totalSeats = ROWS * COLS;
    int seatsReserved = 0;
    while (seatsReserved < totalSeats) {
        // Get user input
        int row;
        char seat;
        cout << "Enter seat number: ";
        cin >> row >> seat;
        cout << endl;

        // Check for valid input
        if (row < 1 || row > ROWS || seat < 'A' || seat >= 'A' + COLS) {
            cout << "Sorry, no such seat exists on the CRJ 200." << endl;
            cout << endl;
            continue;
        }

        // Check if the seat is already reserved
        if (seats[row - 1][seat - 'A'] == 'X') {
            cout << "Seat " << row << seat << " is already reserved. Please choose another seat." << endl;
            cout << endl;
            continue;
        }

        // Reserve the seat
        seats[row - 1][seat - 'A'] = 'X';
        ++seatsReserved;

        // Display updated seating chart
        cout << "Updated seating chart:" << endl;
        for (int col = 0; col < COLS; ++col) {
            cout << "Column " << static_cast<char>('A' + col) << ": ";
            displaySeatColumn(seats, col);
            cout << endl;
        }

        // Check if all seats are filled
        if (seatsReserved == totalSeats) {
            cout << "All seats are filled." << endl;
            cout << endl;
            break;
        }
    }
}

// Find row function
int findRowIndex(int thisRow) {
    return thisRow - 1;
}

// Find seat function
int findSeatIndex(char thisSeat) {
    return thisSeat - 'A';
}

// Display a column of seats
void displaySeatColumn(char seats[][COLS], int column) {
    for (int row = 0; row < ROWS; ++row) {
        cout << setw(3) << seats[row][column];
    }
}