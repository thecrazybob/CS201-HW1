#include <string>
#include "Cabinet.h"
using namespace std;

// Constructor
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
