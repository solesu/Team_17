 #include "Population.hpp"
 #include "Simulation.hpp"
 
//Questions 2)puis-je utiliser valeur avant d'avoir fait cmd.parse ou faire plusieurs fois

 int main(int argc, char ** argv)
 {
 	
 	TCLAP::CmdLine cmd("Simulation parameters");
 	TCLAP::ValueArg<unsigned int> runs_number("r", "runs_number", "How many replicates would you like to create?", false, 0, "unsigned int") ;
 	cmd.add(runs_number);
 	TCLAP::ValueArg<unsigned int> generations_number("g", "generations_number", "Enter the number of generation: ", false, 0, "unsigned int");
 	cmd.add(generations_number);
 	TCLAP::MultiArg<unsigned int> marker_sites("m", "marker_sites",  "Enter the marker sites ", false, "unsigned int");
 	cmd.add(marker_sites);
 	cmd.parse(argc,argv);
 	Simulation s;
 	Population* pop(s.create_pop(generations_number.getValue(), marker_sites.getValue())); 
 	s.launchSimulation(pop, runs_number.getValue());
 	
 	 
 	
 	
 		return 0;
}
