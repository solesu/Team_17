#ifndef VECTORFREQUENCIESCONSTRAINT_H
#define VECTORFREQUENCIESCONSTRAINT_H

#include <string>
#include <vector>

using namespace std;
namespace TCLAP
{

class VectorFrequenciesConstraint
{

public:
		/*!
		 * @brief Virtual destructor 
		 */
		 ~VectorFrequenciesConstraint() {}

		/*!
		 * @brief Returns a description of the Constraint. 
		 */
		string description() const;

		/*!
		 * @brief Returns the short ID for the Constraint.
		 */
		string shortID() const;

		/*!
		 * @brief  
		 * checks if the value entred respects the constraint
		 * @param vector of doubles (the frequencies)
		 */
		bool check (vector<double> const& Vec) const;
		
};

bool VectorFrequenciesConstraint::check(vector<double> const& Vec) const
	{
		double sumFequence (0.0);
		bool isAFreq (true);
		for (auto const& frequence : Vec)
		{
			sumFequence += frequence;
			if (frequence <= 0)
			{
				isAFreq = false;
			}
		}
		
		bool isSum1 (sumFequence > 0.999 and sumFequence < 1.001); 
		
		return !(!isSum1 or !isAFreq); 
	 }

	string VectorFrequenciesConstraint::shortID() const
	{
		string shortID ("postive non zero integer");
		return shortID;
	}

	string VectorFrequenciesConstraint::description() const
	{
		string description ("Frequencies must be positive integers with sum 1");
		return description;	
	}
}
#endif
