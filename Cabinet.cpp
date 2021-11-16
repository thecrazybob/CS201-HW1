#include <string>
#include <iostream>
#include "Cabinet.h"
using namespace std;

// Overload Assignment Operator
Cabinet& Cabinet::operator=( const Cabinet& right ) {

    if ( &right != this ) { // to avoid self-assignment

        id = right.id;
        rows = right.rows;
        columns = right.columns;

        // Initialize first dimension (rows) of 2-D array
        chemicals = new Chemical* [rows];

        // Initialize second dimension (columns) of 2-D array
        for (int i = 0; i < rows; i++) {
            chemicals[i] = new Chemical[columns];
        }

        // Initialize second dimension array with empty Chemical objects
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < columns; j++) {

                chemicals[i][j] = right.chemicals[i][j];

            }

        }

    }

    return *this; // to allow cascading

}

// Constructors

Cabinet::Cabinet() {
    id = 0;
    rows = 0;
    columns = 0;
    chemicals = NULL;
}

Cabinet::Cabinet(int new_id, int new_rows, int new_columns) {

    id = new_id;
    rows = new_rows;
    columns = new_columns;

    // Initialize first dimension (rows) of 2-D array
    chemicals = new Chemical* [rows];

    // Initialize second dimension (columns) of 2-D array
    for (int i = 0; i < rows; i++) {
        chemicals[i] = new Chemical[columns];
    }

    // Initialize second dimension array with empty Chemical objects
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < columns; j++) {

            chemicals[i][j] = Chemical();

        }

    }

}

// Destructor

Cabinet::~Cabinet() {

    for (int i = 0; i < rows; i++) {
        delete [] chemicals[i];
    }

    delete [] chemicals;

}

// Implementation for getter methods

int Cabinet::getId() {
    return id;
}

int Cabinet::getRows() {
    return rows;
}

int Cabinet::getColumns() {
    return columns;
}

int Cabinet::getEmpty() {
    int empty = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (chemicals[i][j].getType() == '+') {
                empty += 1;
            }
        }
    }

    return empty;
}

// Implementation for setter methods

void Cabinet::setId(int new_id) {
    id = new_id;
}

void Cabinet::setRows(int new_rows) {
    rows = new_rows;
}

void Cabinet::setColumns(int new_columns) {
    columns = new_columns;
}

// Methods specific to chemicals

void Cabinet::findChemical(int id) {

}

void Cabinet::showContents() {

}

void Cabinet::placeChemical(string location, char chemType, int chemId) {

    // Number of locations found
    int locationsFound = 0;

    // Number of locations empty
    int empty = this->getEmpty();

    // Array of available locations string (A1, B1, etc.)
    string availableLocations[empty];

    // Check if there is empty space in cabinet
    if (empty <= 0) {
        cout << "There is no available space in the cabinet";
        return;
    }

    // Find empty space
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getColumns(); j++) {

            // Verify if a chemical of the same ID exists
            if (chemicals[i][j].getId() == id) {
                cout << "Chemical with ID " << id << " already exists in the system";
                return;
            }

            if (chemicals[i][j].getType() == '+') {
                availableLocations[locationsFound] = this->indexToLocation(i, j);

                locationsFound++;
            }


        }
    }

    int* locationIndex = this->locationToIndex(location);

    cout << locationIndex[0];

    // // Check if the specificed location is empty
    // if (chemicals[locationIndex[0]][locationIndex[1]].getType() != '+') {
    //     cout << "Location " << location << " in cabinet " << id << " is already occupied. Nearest possible location for this chemical: ";
    //     return;
    // }
    // else {

        // chemicals[locationIndex[0]][locationIndex[1]].setId(chemId);
        // chemicals[locationIndex[0]][locationIndex[1]].setType(chemType);

        // cout << chemType << " chemical with ID " << chemId << " has been placed at location " << location << " in cabinet " << id << endl;

    // }

    // Check if there are top and bottom rows

    // Check if there are columns

    // (a) For each row check not allowed chemical

    // (b) For each column check not allowed chemical

    // If (a) + (b) is greater than 1 then find another empty space and repeat

    // If all empty spaces give (a) + (b) > 0 then do not place chemical

    // Else place chemical



}

void Cabinet::removeChemical(int id) {

}

int * Cabinet::locationToIndex(const string &location) {

    // Manipulate location - C1 = C is column while 1 is row and store it as row and column
    char column = location[0];
    char row = location[1];

    // Outputs
    int * output[2];

    switch (row) {
        case '1':
            *output[0] = 0;

            break;

        case '2':
            *output[0] = 1;

            break;

        case '3':
            *output[0] = 2;

            break;

        case '4':
            *output[0] = 3;

            break;

        case '5':
            *output[0] = 4;

            break;

        case '6':
            *output[0] = 5;

            break;

        case '7':
            *output[0] = 6;

            break;

        case '8':
            *output[0] = 7;

            break;

        case '9':
            *output[0] = 8;

            break;

        default:

            *output[0] = 0;
            break;
    }

    switch (column) {
        case 'A':
            *output[1] = 0;

            break;

        case 'B':
            *output[1] = 1;

            break;

        case 'C':
            *output[1] = 2;

            break;

        case 'D':
            *output[1] = 3;

            break;

        case 'E':
            *output[1] = 4;

            break;

        case 'F':
            *output[1] = 5;

            break;

        case 'G':
            *output[1] = 6;

            break;

        case 'H':
            *output[1] = 7;

            break;

        case 'I':
            *output[1] = 8;

            break;

        default:

            *output[1] = 9;
            break;
    }

    return * output;
}

string Cabinet::indexToLocation(const int &i, const int &j) {

    string row;
    string column;

    switch (i) {
        case 0:
            row = "1";

            break;

        case 1:
            row = "2";

            break;

        case 2:
            row = "3";

            break;

        case 3:
            row = "4";

            break;

        case 4:
            row = "5";

            break;

        case 5:
            row = "6";

            break;

        case 6:
            row = "7";

            break;

        case 7:
            row = "8";

            break;

        case 8:
            row = "9";

            break;

        default:

            row = "1";
            break;
    }

    switch (j) {
        case 0:
            column = "A";

            break;

        case 1:
            column = "B";

            break;

        case 2:
            column = "C";

            break;

        case 3:
            column = "D";

            break;

        case 4:
            column = "E";

            break;

        case 5:
            column = "F";

            break;

        case 6:
            column = "G";

            break;

        case 7:
            column = "H";

            break;

        case 8:
            column = "I";

            break;

        default:

            column = "A";
            break;
    }

    return column + row;
}
