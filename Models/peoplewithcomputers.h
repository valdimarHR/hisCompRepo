#ifndef PEOPLEWITHCOMPUTERS_H
#define PEOPLEWITHCOMPUTERS_H
#include <vector>
#include "Models/computers.h"
#include "Models/people.h"

/**
 * @brief Combines person with a vector of computers to know which one they made.
 */

class peopleWithComputers
{
public:
    peopleWithComputers();
    people p;
    vector<computers> creations;
};

#endif // PEOPLEWITHCOMPUTERS_H

