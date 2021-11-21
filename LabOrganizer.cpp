#include <iostream>
#include <string>
#include "LabOrganizer.h"
using namespace std;

// Constructor

LabOrganizer::LabOrganizer() {

    // Initiate total_cabinets with value of 0
    total_cabinets = 0;

    cabinets = NULL;
}

// Destructor

LabOrganizer::~LabOrganizer() {

    // Delete array of cabinets
    delete [] cabinets;

    // Reset the total number of cabinets
    total_cabinets = 0;
}

// Implementation of methods in LabOrganizer.h

void LabOrganizer::addCabinet(int id, int rows, int columns) {

    // Check if ID already exists
    for (int i = 0; i < total_cabinets; i++) {
        if (cabinets[i].getId() == id) {
            cout << "Cannot add the cabinet: ID " << id << " already in the system\n";
            return;
        }
    }

    // Check if out of bounds
    if (rows > 9 || columns > 9 || rows < 0 || columns < 0) {
        cout << "Cannot add the cabinet: dimensions are out of bounds \n";
        return;
    }

    // If empty - create first cabinet
    if (total_cabinets == 0) {

        cabinets = new Cabinet[1];
        cabinets[0] = Cabinet(id, rows, columns);

    }

    else {

        // New array with the new cabinet object
        Cabinet *new_cabinets = new Cabinet[total_cabinets + 1];

        // Copy over cabinets array to the newly allocated array
        for (int i = 0; i < (total_cabinets); i++) {
            new_cabinets[i] = cabinets[i];
        }

        new_cabinets[total_cabinets] = Cabinet(id, rows, columns);

        // Delete the existing cabinets array
        delete [] cabinets;

        // Point cabinets pointer to the new array
        cabinets = new_cabinets;

    }

    total_cabinets++;

    cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << "\n";

}

void LabOrganizer::removeCabinet(int id) {

    // Determine if a cabinet is removed
    int deleted = 0;
    bool detected = false;

    // Determine if an item needs to be deleted
    for (int i = 0; i < (total_cabinets); i++) {

        if (cabinets[i].getId() == id) {
            deleted = 1;
        }

    }

    if (deleted != 0) {

        // Delete all chemicals inside the cabinet before removing the cabinet
        for (int i = 0; i < total_cabinets; i++) {

            if (cabinets[i].getId() == id) {

                for (int j = 0; j < cabinets[i].getRows(); j++) {

                    for (int k = 0; k < cabinets[i].getColumns(); k++) {

                        if (cabinets[i].chemicals[j][k].getType() != '+') {

                            removeChemical(cabinets[i].chemicals[j][k].getId());

                        }

                    }

                }

            }

        }

        total_cabinets = total_cabinets - 1;

        // New array with the possibly removed cabinet object
        Cabinet *new_cabinets = new Cabinet[total_cabinets];

        // Copy over cabinets array to the newly allocated array
        for (int i = 0; i < total_cabinets; i++) {

            if (cabinets[i].getId() == id) {

                detected = true;

                new_cabinets[i] = cabinets[i + 1];

            }

            else {

                if (!detected) {
                    new_cabinets[i] = cabinets[i];
                }
                else {
                    new_cabinets[i] = cabinets[i + 1];
                }

            }

        }

        // Delete the existing cabinets array
        delete [] cabinets;

        // Point cabinets pointer to the new array

        cabinets = new_cabinets;

        cout << "Cabinet " << id << " has been removed" << endl;

    }
    else {

        cout << "Cabinet " << id << " does not exist in the system" << endl;

    }

}

void LabOrganizer::listCabinets() {

    cout << "List of all cabinets:";
    cout << endl;

    for (int i = 0; i < total_cabinets; i++) {
        cout << "ID: " << cabinets[i].getId() << ", Dim: " << cabinets[i].getRows() << "x" << cabinets[i].getColumns() << ", Number of empty slots: " << cabinets[i].getEmpty() << endl;
    }

}

void LabOrganizer::cabinetContents(int id) {

    bool firstFound = false;

    for (int i = 0; i < total_cabinets; i++) {

        if (cabinets[i].getId() == id) {
            cout << "ID: " << id << ", " << cabinets[i].getRows() << "x" << cabinets[i].getColumns() << ", empty: " << cabinets[i].getEmpty() << ". Chemicals: ";

            // Print table overview
            for (int j = 0; j < cabinets[i].getRows(); j++) {

                for (int k = 0; k < cabinets[i].getColumns(); k++) {

                    if (cabinets[i].chemicals[j][k].getType() != '+') {

                        firstFound ? cout << ", " : cout << "";

                        firstFound = true;

                        cout << cabinets[i].indexToLocation(j,k) << ": " << cabinets[i].chemicals[j][k].getId();

                    }
                }

            }

            cout << endl;

            // Print contents table

            // Print column headings
            for (int j = 0; j < cabinets[i].getColumns(); j++) {
                if (j == 0) {
                    cout << '\t';
                }
                cout << j + 1 << '\t';
            }

            cout << endl;

            // Print row headings
            for (int j = 0; j < cabinets[i].getRows(); j++) {

                cout << cabinets[i].indexToLocation(j, 0)[0] << '\t';

                // Print contents of each row
                for (int k = 0; k < cabinets[i].getColumns(); k++) {
                    cout << cabinets[i].chemicals[j][k].getType() << '\t';
                }

                cout << endl;

            }

            return;
        }

    }

    cout << "Cabinet " << id << " is not in the system";

}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    // Store first character of chemical name as char
    char chemicalType = chemType[0];

    // Capitalize first character of chemical name
    chemType[0] = toupper(chemType[0]);

    // Verify if the same chemical doesn't exist in any cabinet
    for (int i = 0; i < total_cabinets; i++) {

        for (int j = 0; j < cabinets[i].getRows(); j++) {

            for (int k = 0; k < cabinets[i].getColumns(); k++) {

                if (cabinets[i].chemicals[j][k].getId() == chemID) {
                    cout << "Chemical with ID " << chemID << " already exists in the system" << endl;
                    return;
                };

            }
        }
    }

    for (int i = 0; i < total_cabinets; i++) {

        if (cabinets[i].getId() == cabinetId) {

            cabinets[i].placeChemical(location, chemicalType, chemID, chemType);

            return;

        }
    }

}

void LabOrganizer::findChemical(int id) {
    bool chemicalFound = false;

    for (int i = 0; i < total_cabinets; i++) {

        for (int j = 0; j < cabinets[i].getRows(); j++) {

            for (int k = 0; k < cabinets[i].getColumns(); k++) {

                if (cabinets[i].chemicals[j][k].getId() == id) {
                    cout << "Chemical " << id << " is at location " << cabinets[i].indexToLocation(j, k) << " in cabinet " << cabinets[i].getId() << endl;
                    chemicalFound = true;
                    return;
                };

            }
        }
    }

    if (!chemicalFound) {
        cout << "Chemical " << id << " is not in the system" << endl;
    }
}

void LabOrganizer::removeChemical(int id) {

    for (int i = 0; i < total_cabinets; i++) {

        for (int j = 0; j < cabinets[i].getRows(); j++) {

            for (int k = 0; k < cabinets[i].getColumns(); k++) {

                if (cabinets[i].chemicals[j][k].getId() == id) {

                    cabinets[i].chemicals[j][k].setId(0);
                    cabinets[i].chemicals[j][k].setLocation("");
                    cabinets[i].chemicals[j][k].setType('+');

                    cout << "Chemical " << id << " removed from cabinet " << cabinets[i].getId() << endl;

                    return;
                }

            }

        }

    }

    cout << "Chemical " << id << " is not in the system" << endl;
}

// Additionally added methods
int LabOrganizer::totalCabinets() {
    return total_cabinets;
}
