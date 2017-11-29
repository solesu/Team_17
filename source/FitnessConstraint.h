/*!
 * Creates a class that constraints the fitness to be bigger than -1
 */ 

#ifndef FITNESSCONSTRAINT_H
#define FITNESSCONSTRAINT_H

#include <string>
#include "../tclap/include/tclap/Constraint.h"

using namespace TCLAP;
using namespace std;

class FitnessConstraint: public Constraint<double>
{
public:
    /*! @brief 
     * Virtual destructor
     */
    virtual ~FitnessConstraint() {}
    
    /*! @brief 
     * Returns a description of the Constraint
     */
    virtual string description() const;
    
    /*! @brief 
     * Returns the short ID for the Constraint
     */
    virtual string shortID() const;

    /*!
	 * @brief 
	 * checks if the value entred respects the constraint
	 */
    virtual bool check (double const& value) const; 
};

bool FitnessConstraint::check (double const& val) const
{
    return (val > -1); 
}

string FitnessConstraint::shortID() const
{
    string shortID ("bigger than -1");
    return shortID;
}

string FitnessConstraint::description() const
{
    string description ("must be bigger than -1");
    return description;
}

#endif
