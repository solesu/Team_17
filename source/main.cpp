#include <./tclap/include/tclap/CmdLine.h>
#include <iostream>
#include "Population.hpp"
#include "Simulation.hpp"

//Questions: 1) Problème dossier TCLAP
//			 2)puis-je utiliser valeur avant d'avoir fait cmd.parse ou faire plusieurs fois


Population* parse_args(int argc, char **argv ) 
{
	TCLAP::CmdLine cmd("Population parameters");
    TCLAP::ValueArg<char> method("m", "method", "Would you like to choose the number or alleles (press A) or to provide us with a fasta file (press F)? " , true , "char");
			
		if(method.getValue()=='A') ///Est-il possible d'utilise alors qu'on a pas fait cmd.parse ? -> sort du bloc if grrrr
		{
			TCLAP::ValueArg<unsigned int> population_size("p", "population_size", "Enter the population size: ", false, 1000, "unsigned int");
			cmd.add(population_size);
			TCLAP::ValueArg<unsigned int> generations_number("g", "generations_number", "Enter the number of generation: ", false, 2, "unsigned int");
			cmd.add(generations_number);
			TCLAP::ValueArg<unsigned int> alleles_number("a", "alleles_number", "Enter the number of different alleles: ", false, 2, "unsigned int");
			cmd.add(alleles_number);
			TCLAP::MultiArg<double> alleles_frequency("f", "alleles_frequency", "Enter the frequency of the alleles ", true, "double");
			cmd.add(alleles_frequency);
		} //else fasta format
		
		// Parse the argv array
		cmd.parse(argc, argv);
		
		unsigned int p = population_size.getValue();
		unsigned int g = generations_number.getValue();
		unsigned int a =  alleles_number.getValue();
		vector<double> f= alleles_frequency.getValue();
		
		Population* pop = new Population(p,g,a,f);
		return pop;

}

int main(int argc, char ** argv)
{
	try 
	{  
		std::cout << "How many times would you like to run the program with the same parameters?" << std::endl;
		Population *(&parse_args(argc, argv)); 
		Simulation s;
		s.launchSimulation(pop, runs_number);
	
	} 
	catch (TCLAP::ArgException &e)  // catch any exceptions
	{ 
			std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; 
	}
	
		return 0;
}
