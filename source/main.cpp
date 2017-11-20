#include <tclap/CmdLine.h>
#include <iostream>
#include "Population.hpp"
#include "Simulation.hpp"

//Questions 2)puis-je utiliser valeur avant d'avoir fait cmd.parse ou faire plusieurs fois

using namespace TCLAP;
using namespace std;

Population* parse_args(int argc, char **argv ) 
{
	CmdLine cmd("Population parameters");
	unsigned int option(0);
	std::cout << "Would you like to choose the number or alleles (press 1) or to provide us with a fasta file (press 2)?" << std::endl;
	std::cin>> option;
			
		if(option==1) ///Est-il possible d'utilise alors qu'on a pas fait cmd.parse ? -> sort du bloc if grrrr
		{
			ValueArg<unsigned int> population_size("p", "population_size", "Enter the population size: ", false, 1000, "unsigned int");
			cmd.add(population_size);
			ValueArg<unsigned int> generations_number("g", "generations_number", "Enter the number of generation: ", false, 2, "unsigned int");
			cmd.add(generations_number);
			ValueArg<unsigned int> alleles_number("a", "alleles_number", "Enter the number of different alleles: ", false, 2, "unsigned int");
			cmd.add(alleles_number);
			MultiArg<double> alleles_frequency("f", "alleles_frequency", "Enter the frequency of the alleles ", true, "double");
			cmd.add(alleles_frequency);
			
			// Parse the argv arra
			cmd.parse(argc, argv);
		
		Population* pop = new Population(population_size.getValue(),generations_number.getValue(), alleles_number.getValue(),alleles_frequency.getValue());
		
		return pop;
		
		} //else fasta format
		
		

}

int main(int argc, char ** argv)
{
	try 
	{  
		unsigned int runs_number;
		std::cout << "How many times would you like to run the program with the same parameters?" << std::endl;
		std::cin>> runs_number;
		Population* pop(parse_args(argc, argv)); 
		Simulation s;
		s.launchSimulation(pop, runs_number);
	
	} 
	catch (TCLAP::ArgException &e)  // catch any exceptions
	{ 
			std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; 
	}
	
		return 0;
}
