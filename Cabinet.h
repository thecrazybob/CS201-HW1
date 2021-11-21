// Mohammed Sohail
// 22001513

#include "Chemical.h"
using namespace std;

class Cabinet {

    private:

        // Unique identifier
        int id;

        // Number of rows (should be restricted to a maximum of 9)
        int rows;

        // Number of columns (should be restricted to a maximum of 9)
        int columns;


    public:

        // Dynamically allocated array of chemicals
        Chemical** chemicals;

        Cabinet(int new_id, int new_rows, int new_columns);
        Cabinet();
        ~Cabinet();
        Cabinet& operator=(const Cabinet&);

        // Getter methods
        int getId();
        int getRows();
        int getColumns();
        int getEmpty();

        // Setter methods
        void setId(int new_id);
        void setRows(int new_rows);
        void setColumns(int new_columns);
        void placeChemical(string location, char chemType, int chemId, string chemName);

        // Helper methods
        int * locationToIndex(const string &location);
        string indexToLocation(const int &i, const int &j);
        bool isNeighborCombustant(string location);
        string * nearestLocations(string location, int &locationsFound, char type);

};
