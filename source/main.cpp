#include <tclap/CmdLine.h>
#include <fstream>
#include <iostream>
#include "Population.hpp"
#include "Simulation.hpp"
#include "VectorFrequenciesConstraint.h"
#include "FitnessConstraint.h"
#include "VectorConstraintTCLAP.h"
using namespace TCLAP;
using namespace std;



int main(int argc, char * argv [])
 {
	VectorFrequenciesConstraint ConstraintFreq;
	FitnessConstraint constraintFitness;
    VectorConstraintTCLAP ConstraintSum1;

	 
 	TCLAP::CmdLine cmd("Simulation parameters");
 	TCLAP::ValueArg<unsigned int> runs_number("r", "runs_number", "How many replicates would you like to create?", false, 0, "unsigned int") ;
 	cmd.add(runs_number);
 	TCLAP::ValueArg<unsigned int> generations_number("g", "generations_number", "Enter the number of generation: ", false, 0, "unsigned int");
 	cmd.add(generations_number);
 	TCLAP::MultiArg<unsigned int> marker_sites("m", "marker_sites",  "Enter the marker sites ", false, "unsigned int");
 	cmd.add(marker_sites);
 	//UnlabeledMultiArg<double> alleles_frequencies ("alleles_frequencies", "vector of frequencies default values 0,1 0,1 0,3 0,5", false, "double");
	//cmd.add (alleles_frequencies);
 	cmd.parse(argc,argv);
 	
 	/*vector<double> allelesFrequencies (alleles_frequencies.getValue());
 	if (allelesFrequencies.empty())
        {
            allelesFrequencies = {0.1, 0.1, 0.3, 0.5};
        }*/
 	Simulation s;
 	Population* pop(s.create_pop(generations_number.getValue(), marker_sites.getValue())); 
 	s.launchSimulation(pop);//, runs_number.getValue());
 	return 0; 
}
 	/*void print (ostream& fStream, Population& Pool, 
			  unsigned int const& generations_number)
{
	 Random randm;
	Random& r=randm;
	
	cout << "Les fréquences initiales sont: ";
	Pool.print(cout);
	cout << endl; 
	
	
	fStream << 0;
	Pool.print (fStream);
	fStream << endl; 
	
	for (unsigned int i(0); i < generations_number; i++)
	{
		fStream << i+1;
		Pool.update(r);
		Pool.print(fStream);
		fStream << endl; 
	}
}

*/
