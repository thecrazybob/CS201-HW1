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

        // Dynamically allocated array of chemicals
        Chemical** chemicals;

    public:

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

        void findChemical(int id);
        void showContents();
        void placeChemical(string location, char chemType, int chemId);
        void removeChemical(int id);

        // Helper methods
        int * locationToIndex(const string &location);
        string indexToLocation(const int &i, const int &j);

};
