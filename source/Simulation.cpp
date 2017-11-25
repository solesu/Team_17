#include "Simulation.hpp"
#include <iostream>

void Simulation::launchSimulation(Population* p, unsigned int runs_number)
{   Random randm;
	Random& r=randm;
	for(unsigned int i(0); i<runs_number; ++i) //Will run the simulation with the same parameters runs_number times
	{
		p->update(r);
		p->print(std::cout);
	} 
}

		
Population* Simulation::create_pop(unsigned int generation_number, std::vector<unsigned int> marker_sites)
{

//Fasta crée pop avec valeurs a l'interieur + generation numbers

}





