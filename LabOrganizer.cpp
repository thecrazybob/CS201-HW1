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

        // Delete new array
        // delete [] new_cabinets;

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

}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    char chemicalType = chemType[0];

    for (int i = 0; i < total_cabinets; i++) {
        if (cabinets[i].getId() == cabinetId) {

            cabinets[i].placeChemical(location, chemicalType, chemID);

        }
    }

}

void LabOrganizer::findChemical(int id) {

}

void LabOrganizer::removeChemical(int id) {

}

// Additionally added methods
int LabOrganizer::totalCabinets() {
    return total_cabinets;
}
