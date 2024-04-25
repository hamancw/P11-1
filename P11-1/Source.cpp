#include <iostream>
#include <string>

using namespace std;

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
const int ROWS = 13;
void displaySeatColumn(char seats[][ROWS], int column);

int main() {

	string seatCode;
	int rowNumber;
	char seatLetter;
	char seatingRegister[6][13] =
	{
	{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', ' '},
	{'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1'},
	{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3'},
	{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
	{'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
	};

	displaySeatColumn(seatingRegister, 1);

	cout << "\nEnter a seat or Q to quit: ";
	cin >> seatCode;

	do
	{

		if (seatCode == "q" || seatCode == "Q")
		{
			break;
		}

		char seatCodeChar1 = seatCode[0];
		char seatCodeChar2 = seatCode[1];
		char seatCodeChar3 = seatCode[2];

		if (isdigit(seatCodeChar1) && isdigit(seatCodeChar2))
			rowNumber = stoi(seatCode.substr(0, 2));
		else if (isdigit(seatCodeChar1))
			rowNumber = stoi(seatCode.substr(0, 1));

		if (isalpha(seatCodeChar2))
			seatLetter = seatCodeChar2;
		else if (isalpha(seatCodeChar3))
			seatLetter = seatCodeChar3;

		if (findSeatIndex(seatLetter) == 13 || findRowIndex(rowNumber) > 12)
		{
			cout << "\nThat is not a proper seat index.\n";
		}
		else if (seatingRegister[findSeatIndex(seatLetter)][findRowIndex(rowNumber)] == 'X')
		{
			cout << "\nThat seat is already taken.\n";
		}
		else if (findRowIndex(rowNumber) == 12 && findSeatIndex(seatLetter) == 0 || findRowIndex(rowNumber) == 12 && findSeatIndex(seatLetter) == 1)
		{
			cout << "\nThat is not a proper seat index.\n";
		}
		else if (findSeatIndex(seatLetter) != 13 && findRowIndex(rowNumber) < 13 && seatingRegister[findSeatIndex(seatLetter)][findRowIndex(rowNumber)] != 'X')
		{
			seatingRegister[findSeatIndex(seatLetter)][findRowIndex(rowNumber)] = 'X';
		}

		displaySeatColumn(seatingRegister, 1);

		cout << "\nEnter a seat or Q to quit: ";
		cin >> seatCode;

	} while (true);


}

int findRowIndex(int thisRow)
{
	return --thisRow;
}

int findSeatIndex(char thisSeat)
{
	switch (thisSeat)
	{
	case 'D':
		return 0;
	case 'C':
		return 1;
	case 'B':
		return 4;
	case 'A':
		return 5;
	default:
		return 13;
	}
}

void displaySeatColumn(char seats[][ROWS], int column)
{

	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		if (i == 2 || i == 4)
			cout << endl;
		for (int j = 0; j < 13; j++)
		{
			cout << seats[i][j] << " ";
		}

		cout << endl;
	}
}