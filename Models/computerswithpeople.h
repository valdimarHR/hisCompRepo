#ifndef COMPUTERSWITHPEOPLE_H
#define COMPUTERSWITHPEOPLE_H
#include <vector>
#include "Models/people.h"
#include "Models/computers.h"

/**
 * @brief Combines computer with a vector of people to know who made it.
 */

class computersWithPeople
{
public:
    computersWithPeople();
    computers c;
    vector<people> creators;
};

#endif // COMPUTERSWITHPEOPLE_H

