#include <iostream>
#include <vector>
#include <cmath>


int main () {
    
    int start[2], finish[2], charge;
    std::cin >> start[0] >> start[1] >> finish[0] >> finish[1] >> charge;
    int diff_x = abs(finish[0] - start[0]);
    int diff_y = abs(finish[1] - start[1]);
    int chargeNeeded = diff_x + diff_y;
    if (charge < chargeNeeded || (charge - chargeNeeded) % 2 == 1) { // odd amount of charge left or not enough
        std::cout << "N";
    } else {
        std::cout << "Y";
    }
    
    return 0;
}
