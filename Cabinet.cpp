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

    id = 0;
    rows = 0;
    columns = 0;

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

void Cabinet::placeChemical(string location, char chemType, int chemId, string chemName) {

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

            if (chemicals[i][j].getType() == '+') {
                availableLocations[locationsFound] = this->indexToLocation(i, j);

                locationsFound++;
            }


        }
    }

    int * locationIndex = this->locationToIndex(location);

    // cout << "location: " << location << " locationIndex: " << locationIndex[0] << " locationIndex: " << locationIndex[1] << " cabinet: " << id << " chemical: " << chemicals[locationIndex[0]][locationIndex[1]].getType() << endl;

    // Verify if the specificed location is empty
    if (chemicals[locationIndex[0]][locationIndex[1]].getType() != '+') {

        cout << "Location " << location << " in cabinet " << id << " is already occupied. Nearest possible location for this chemical: " << endl;
        return;

    }
    else {

        // The chemical is not retardant
        if (chemType != 'r') {
            bool haveTopRow;
            bool haveBottomRow;
            bool haveLeftCol;
            bool haveRightCol;

            bool dangerous = false;

            // Check if there are top and bottom rows
            haveTopRow = rows - locationIndex[0] == rows ? false : true;
            haveBottomRow = rows - locationIndex[0] == 1 ? false : true;

            // Check if there are left and right columns
            haveLeftCol = columns - locationIndex[1] == columns ? false : true;
            haveRightCol = columns - locationIndex[1] == 1 ? false : true;

            // (a) For each row check not allowed chemical
            // (b) For each column check not allowed chemical
            if (haveTopRow) {
                chemicals[locationIndex[0]-1][locationIndex[1]].getType() == 'c' ? dangerous = true : dangerous = dangerous;
            }

            if (haveBottomRow) {
                chemicals[locationIndex[0]+1][locationIndex[1]].getType() == 'c' ? dangerous = true : dangerous = dangerous;
            }

            if (haveLeftCol) {
                chemicals[locationIndex[0]][locationIndex[1]-1].getType() == 'c' ? dangerous = true : dangerous = dangerous;
            }

            if (haveRightCol) {
                chemicals[locationIndex[0]][locationIndex[1]+1].getType() == 'c' ? dangerous = true : dangerous = dangerous;
            }

            if (haveTopRow && haveLeftCol) {
                chemicals[locationIndex[0]-1][locationIndex[1]-1].getType() == 'c' ? dangerous = true : dangerous = dangerous;
            }

            if (haveTopRow && haveRightCol) {
                chemicals[locationIndex[0]-1][locationIndex[1]+1].getType() == 'c' ? dangerous = true : dangerous = dangerous;
            }

            if (haveBottomRow && haveLeftCol) {
                chemicals[locationIndex[0]+1][locationIndex[1]-1].getType() == 'c' ? dangerous = true : dangerous = dangerous;
            }

            if (haveBottomRow && haveRightCol) {
                chemicals[locationIndex[0]+1][locationIndex[1]+1].getType() == 'c' ? dangerous = true : dangerous = dangerous;
            }

            if (dangerous) {
                cout << "Location " << location << " in cabinet " << id << " is not suitable for a combustive chemical. Nearest possible locations for this chemical: " << endl;
                return;
            }

        }

        // Else place chemical
        chemicals[locationIndex[0]][locationIndex[1]].setId(chemId);
        chemicals[locationIndex[0]][locationIndex[1]].setType(chemType);

        cout << chemName << " chemical with ID " << chemId << " has been placed at location " << location << " in cabinet " << id << endl;

    }


}

void Cabinet::removeChemical(int id) {

}

int * Cabinet::locationToIndex(const string &location) {

    // Manipulate location
    char row = location[0];
    char column = location[1];

    // Outputs
    static int output[2];

    switch (row) {
        case 'A':
            output[0] = 0;

            break;

        case 'B':
            output[0] = 1;

            break;

        case 'C':
            output[0] = 2;

            break;

        case 'D':
            output[0] = 3;

            break;

        case 'E':
            output[0] = 4;

            break;

        case 'F':
            output[0] = 5;

            break;

        case 'G':
            output[0] = 6;

            break;

        case 'H':
            output[0] = 7;

            break;

        case 'I':
            output[0] = 8;

            break;

        default:

            output[0] = 9;
            break;
    }

    switch (column) {
        case '1':
            output[1] = 0;

            break;

        case '2':
            output[1] = 1;

            break;

        case '3':
            output[1] = 2;

            break;

        case '4':
            output[1] = 3;

            break;

        case '5':
            output[1] = 4;

            break;

        case '6':
            output[1] = 5;

            break;

        case '7':
            output[1] = 6;

            break;

        case '8':
            output[1] = 7;

            break;

        case '9':
            output[1] = 8;

            break;

        default:

            output[1] = 0;
            break;
    }

    return output;
}

string Cabinet::indexToLocation(const int &i, const int &j) {

    string row;
    string column;

    switch (i) {
        case 0:
            row = "A";

            break;

        case 1:
            row = "B";

            break;

        case 2:
            row = "C";

            break;

        case 3:
            row = "D";

            break;

        case 4:
            row = "E";

            break;

        case 5:
            row = "F";

            break;

        case 6:
            row = "G";

            break;

        case 7:
            row = "H";

            break;

        case 8:
            row = "I";

            break;

        default:

            row = "A";
            break;
    }

    switch (j) {
        case 0:
            column = "1";

            break;

        case 1:
            column = "2";

            break;

        case 2:
            column = "3";

            break;

        case 3:
            column = "4";

            break;

        case 4:
            column = "5";

            break;

        case 5:
            column = "6";

            break;

        case 6:
            column = "7";

            break;

        case 7:
            column = "8";

            break;

        case 8:
            column = "9";

            break;

        default:

            column = "1";
            break;
    }

    return row + column;
}
