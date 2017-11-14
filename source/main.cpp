#include <tclap/include/CmdLine.h>
#include <iostream>

int main(int argc, char ** argv)
{
	try 
	{  
		// Define the command line object, and insert a message
		// that describes the program.
		TCLAP::CmdLine cmd("Command description message");
		TCLAP::ValueArg<unsigned int> runs_number("r", "runs_number", "How many times do you want to run the program with the same parameters? ", false, 1 , "unsigned int");
		cmd.add(runs_number);
		
		TCLAP::ValueArg<char> method("m", "method", "Would you like to choose the number or alleles (press A) or to provide us with a fasta file (press F)? " , true , "char");
		
		if(method.getValue()=='A') //Est-il possible d'utilise alors qu'on a pas fait cmd.parse
		{
			TCLAP::ValueArg<unsigned int> population_size("p", "population_size", "Enter the population size: ", false, 1000, "unsigned int");
			cmd.add(population_size);
			TCLAP::ValueArg<unsigned int> generations_number("g", "generations_number", "Enter the number of generation: ", false, 2, "unsigned int");
			cmd.add(generations_number);
			TCLAP::ValueArg<unsigned int> alleles_number("a", "alleles_number", "Enter the number of different alleles: ", false, 2, "unsigned int");
			cmd.add(alleles_number);
			TCLAP::MultiArg<double> alleles_frequency("f", "alleles_frequency", "Enter the frequency of the alleles ", true, "double");
			cmd.add(alleles_frequency);
		}
		// Parse the argv array
		cmd.parse(argc, argv);
		
		//FASTA FORMAT else
		
		Population(population_size.getValue(), generations_number.getValue(), alleles_number.getValue(), alleles_frequency.getValue());
	
	} 
	catch (TCLAP::ArgException &e)  // catch any exceptions
		{ 
			std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; 
		}
	
		return 0;
}
