#include <string>
#include "Chemical.h"
using namespace std;

// Constructors

Chemical::Chemical() {
    id = 0;
    type = '+';
    location = "";
}

Chemical::Chemical(int new_id, char new_type, string new_location) {
    id = new_id;
    type = new_type;
    location = new_location;
}

// Implementations for methods in "Chemical.h"

int Chemical::getId() {
    return id;
}

char Chemical::getType() {
    return type;
}

string Chemical::getLocation() {
    return location;
}

void Chemical::setId(int new_id) {
    id = new_id;
}

void Chemical::setType(char new_type) {
    type = new_type;
}

void Chemical::setLocation(string new_location) {
    location = new_location;
}
