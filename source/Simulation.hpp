#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Population.hpp"
#include <tclap/CmdLine.h>


/**
* The class Simulation manages the user defined parameters and launches the experiment
*/

class Simulation
{
	public:
		
		/**
		 * creates a new population with the values decided by the user
		 */
		 void launchSimulation(Population* p, unsigned int runs_number);
		 Population* create_pop(unsigned int generation_number, std::vector<unsigned int> marker_sites);
		
		
};

#endif

