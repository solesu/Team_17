#include <tclap/CmdLine.h>
#include <iostream>
#include "Population.hpp"
#include "Simulation.hpp"

//Questions 2)puis-je utiliser valeur avant d'avoir fait cmd.parse ou faire plusieurs fois



int main(int argc, char ** argv)
{
	  
	unsigned int runs_number;
	std::cout << "How many replicates would you like to create?" << std::endl;
	std::cin>> runs_number;
	Simulation s;
	Population* pop(s.parse_args(argc, argv)); 
	s.launchSimulation(pop, runs_number);
	
	 
	
	
		return 0;
}
