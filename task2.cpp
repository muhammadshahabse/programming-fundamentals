#include <iostream>
#include <iomanip>
using namespace std;

struct Seat {
    char status;
};

int main() {
    Seat seatarr[9][6];

    int row, column, morebooking = 1, check = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 6; j++) {
            seatarr[i][j].status = 'F';
        }
    }

    cout << "\t       -------------------------" << endl;
    for (int i = 0; i < 9; i++) {
        if (i == 0) {
            cout << "\t\tC.No->";
            cout << "1-2-3-4-5|    |6|" << endl;
            cout << "\t\tR.No";
            cout << "|-------------------" << endl;
        } else {
            if (i % 2 == 0)
                cout << "\t\t    |----------|    |-|" << endl;
        }

        cout << "\t\t" << i + 1 << ")  ";
        cout << "|";

        for (int j = 0; j < 6; j++) {
            if (j == 5)
                cout << "|    |" << seatarr[i][j].status;
            else
                cout << " " << seatarr[i][j].status;
        }

        cout << "|" << endl;
    }

    cout << "\t      -------------------------" << endl;

    do {
        cout << "\t\tROW.No: ";
        cin >> row;
        if (row > 0 && row <= 9) {
            cout << "\t\tCOLUMN.No: ";
            cin >> column;
            if (column > 0 && column <= 6) {
                if (seatarr[row - 1][column - 1].status == 'B') {
                    cout << "Seat is already booked" << endl;
                    cout << "Try again later." << endl;
                    continue;
                } else {
                    seatarr[row - 1][column - 1].status = 'B';
                }

                cout << "\t       -------------------------" << endl;
                for (int i = 0; i < 9; i++) {
                    if (i == 0) {
                        cout << "\t\tC.No->";
                        cout << "1-2-3-4-5|    |6|" << endl;
                        cout << "\t\tR.No";
                        cout << "|-------------------" << endl;
                    } else {
                        if (i % 2 == 0)
                            cout << "\t\t    |----------|    |-|" << endl;
                    }

                    cout << "\t\t" << i + 1 << ")  ";
                    cout << "|";

                    for (int j = 0; j < 6; j++) {
                        if (j == 5)
                            cout << "|    |" << seatarr[i][j].status;
                        else
                            cout << " " << seatarr[i][j].status;
                    }

                    cout << "|" << endl;
                }

                cout << "\t      -------------------------" << endl;
                cout << "Enter any key for more booking and 0 for exit: ";
                cin >> morebooking;
            } else {
                cout << "Invalid input. Please enter column between 1 and 6." << endl;
            }
        } else {
            cout << "Invalid input. Please enter row between 1 and 9." << endl;
        }
    } while (morebooking != 0);

    cout << "Thank you for using our service" << endl;
    cout << "The program is terminating now" << endl;

    return 0;
}
