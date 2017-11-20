#include "Simulation.hpp"

#include <iostream>

void Simulation::launchSimulation(Population* p, unsigned int runs_number)
{ 
	/*for(unsigned int i(0); i<runs_number; ++i) //Will run the simulation with the same parameters runs_number times
	{
		//Faire simulation avec génération
	} */
	
	std::ifstream input(sequence.fasta);
    if(!input.good())
    {
        std::cerr << "Error while opening the file. Sorry. Oops." << std::endl;
        return -1;
    }
 
    std::string line, name, content;
    while(std::getline(input, line).good())
    {
        if(line.empty() || line[0] == '>') // Identifier marker
        { 
            if(!name.empty()) // Print out what we read from the last entry
            { 
                std::cout << name << " : " << content << std::endl;
                name.clear();
            }
            if(!line.empty())
            {
                name = line.substr(1);
            }
            content.clear();
        } else if(!name.empty())
        {
            if(line.find(' ') != std::string::npos)
            { // Invalid sequence--no spaces allowed
                name.clear();
                content.clear();
            } else 
            {
                content += line;
            }
        }
    }
    
    if(!name.empty()) // Print out what we read from the last entry
    { 
        std::cout << name << " : " << content << std::endl;
    }
	
	
}



