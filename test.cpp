#include <iostream>
#include "LabOrganizer.h"
using namespace std;

int main() {

    Chemical c1 = Chemical(1, 'r', "A1");

    cout << "c1's id: " << c1.getId() << "\n";
    cout << "c1's type: " << c1.getType() << "\n";

    LabOrganizer l1 = LabOrganizer();
    l1.addCabinet(1, 4, 5);
    cout << "Total cabinets: " << l1.totalCabinets();

}
