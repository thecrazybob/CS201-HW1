// Mohammed Sohail
// 22001513

#include "Cabinet.h"
#include <string>

class LabOrganizer {

    private:

        // Dynamically allocated array of cabinets
        Cabinet * cabinets;
        int total_cabinets;

    public:

        // Constructor
        LabOrganizer();

        // Destructor
        ~LabOrganizer();

        // Prototypes of methods for LabOrganizer class
        void addCabinet(int id, int rows, int columns);
        void removeCabinet(int id);
        void listCabinets();
        void cabinetContents(int id);
        void placeChemical(int cabinetId, string location, string chemType, int chemID);
        void findChemical(int id);
        void removeChemical(int id);

        // ...
        //you may define additional member functions and data members, if necessary
        int totalCabinets();
};
