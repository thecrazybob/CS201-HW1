#include <string>
using namespace std;

class Chemical {

    private:

        // Unique identifier
        int id;

        // Type of chemical ( retardant (r) or combustive (c) )
        char type;

        // Location of chemical
        string location;

    public:

        // Constructor and destructor methods
        Chemical();
        Chemical(int new_id, char new_type, string location);

        // Getter methods
        int getId();
        char getType();
        string getLocation();

        // Setter methods
        void setId(int new_id);
        void setType(char new_type);
        void setLocation(string new_location);

};
