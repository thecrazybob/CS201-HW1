#include <iostream>
#include <string>
#include "LabOrganizer.h"
using namespace std;

// Constructor

LabOrganizer::LabOrganizer() {

    // Initiate total_cabinets with value of 0
    total_cabinets = 0;

    cabinets = new Cabinet[0];
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

    // Increment number of cabinets
    total_cabinets += 1;

    // New array with the new cabinet object
    Cabinet *new_cabinets = new Cabinet[total_cabinets];

    // Copy over cabinets array to the newly allocated array
    for (int i = 0; i < (total_cabinets - 1); i++) {
        new_cabinets[i] = cabinets[i];
    }

    // Store the index of the new element to be added
    int indexOfNewElement = total_cabinets - 1;

    // Initialize newly added cabinet
    new_cabinets[indexOfNewElement] = Cabinet(id, rows, columns);

    // // Delete the existing cabinets array
    // delete [] cabinets;

    // // Point cabinets pointer to the new array
    // cabinets = new_cabinets;


}

void LabOrganizer::removeCabinet(int id) {

}

void LabOrganizer::listCabinets() {

}

void LabOrganizer::cabinetContents(int id) {

}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {

}

void LabOrganizer::findChemical(int id) {

}

void LabOrganizer::removeChemical(int id) {

}

// Additionally added methods
int LabOrganizer::totalCabinets() {
    return total_cabinets;
}
