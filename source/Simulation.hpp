#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>


/**
* The class Simulation manages the user defined parameters and launches the experiment
*/

class Simulation
{
	public:
		
		/**
		 * creates a new population with the values decided by the user
		 */
		 void launchSimulation();
		
		/**
		 * @return the number of time the user wants to run the program with the same parameters
		 */
		unsigned int runsNumber();
		
		/**
		 * @return the population size according to the user's desire
		 */
		unsigned int populationSize();
		
		/**
		 * @return the number of generation according to the user's desire
		 */
		unsigned int generationsNumber();
		
		/**
		 * @return the number of alleles according to the user's desire
		 * The user can provide either a number of alleles or a files containing the alleles -> fasta format
		 */
		unsigned int allelesNumber();
		
		/**
		 * @return the frequency of each alleles
		 */
		std::vector<double> allelesFrequency(unsigned int alleles_number);
};

#endif

