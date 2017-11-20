#include "Simulation.hpp"
#include <iostream>

void Simulation::launchSimulation(Population* p, unsigned int runs_number)
{ 
	for(unsigned int i(0); i<runs_number; ++i) //Will run the simulation with the same parameters runs_number times
	{
		//Faire simulation avec génération
	} 
}

Population* Simulation::parse_args(int argc, char **argv){
	CmdLine cmd("Population parameters");
	unsigned int option(0);
	std::cout << "Would you like to choose the number or alleles (press 1) or to provide us with a fasta file (press 2)?" << std::endl;
	std::cin>> option;
			
		if(option==1) ///Est-il possible d'utilise alors qu'on a pas fait cmd.parse ? -> sort du bloc if grrrr
		{
			TCLAP::ValueArg<unsigned int> population_size("p", "population_size", "Enter the population size: ", false, 1000, "unsigned int");
			cmd.add(population_size);
			TCLAP::ValueArg<unsigned int> generations_number("g", "generations_number", "Enter the number of generation: ", false, 2, "unsigned int");
			cmd.add(generations_number);
			TCLAP::ValueArg<unsigned int> alleles_number("a", "alleles_number", "Enter the number of different alleles: ", false, 2, "unsigned int");
			cmd.add(alleles_number);
			TCLAP::MultiArg<double> alleles_frequency("f", "alleles_frequency", "Enter the frequency of the alleles ", true, "double");
			cmd.add(alleles_frequency);
			
			// Parse the argv arra
			cmd.parse(argc, argv);
		
		Population* pop = new Population(population_size.getValue(),generations_number.getValue(), alleles_number.getValue(),alleles_frequency.getValue());
		
		return pop;
		
		} //else fasta format

}



