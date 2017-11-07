#include "Simulation.hpp"
#include <iostream>

/**
 * Constructor
 */
Simulation::Simulation()
{
	unsigned int runs_number(runsNumber()); 
	for(unsigned int i(0); i<runs_number; ++i) //Will run the simulation with the same parameters runs_number times
	{
		std::cout <<"Would you like to choose the number or alleles (press 1) or to provide us with a fasta file (press 2)?" << std::endl;
		unsigned int option;
		std::cin >> option;
		
		unsigned int size(populationSize());
		unsigned int time(generationsNumber());
		
		if(option==1)
		{
			unsigned int alleles_number(allelesNumber());
		}
		///Find a way to deal with fasta format
		/*else
		{
		}*/
		//Population p(populationSize(), generationsNumber(), alleles_number, allelesFrequency(alles_number));
	}


}

unsigned int Simulation::runsNumber()
{
	unsigned int runs_number;
	do
	{
		std::cout << "How many times do you want to run the program with the same parameters?" << std::endl;
	}while (runs_number%1!=0);
	std::cin>>runs_number;
	return runs_number;
}

unsigned int Simulation::populationSize()
{
	unsigned int size;
		do
		{
			std::cout << "Enter the population size: " << std::endl;
		}while (size>=1 and size%1==0);
		std::cin>> size;
	return size;
}
unsigned int Simulation::generationsNumber()
{
	unsigned int time;
		do
		{
			std::cout << "Enter the number of generation: " << std::endl;
		}while (time>=1 and time%1==0);
		std::cin>> time;
	return time;
}
unsigned int Simulation::allelesNumber()
{
	unsigned int alleles_number;
		do
		{
			std::cout << "Enter the number of different alleles: " << std::endl;
		}while (alleles_number>=1 and alleles_number%1==0);
		std::cin>> alleles_number;
	return alleles_number;
}
std::vector<double> Simulation::allelesFrequency(unsigned int alleles_number)
{
	std::vector<double> frequencies;
		double count(0);
		do
		{
			double frequency;
			for(unsigned int i(0); i<alleles_number; ++i)
			{
				count+=frequency;
				do
				{
					std::cout << "Enter the frequency of the allele " << i+1 << ": " << std::endl;
				}while (frequency<=1 and frequency>=0);
				std::cin>> frequency;
				frequencies.push_back(frequency);
			}
		}while(count!=1); //The addition of all the frequencies must be equal to 1
	return frequencies;
}
