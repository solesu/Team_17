#include "Simulation.hpp"

#include <iostream>
#include <fstream>
#include <vector>

void Simulation::launchSimulation(Population* p, unsigned int runs_number)
{
    Random randm;
	Random& r=randm;
	for(unsigned int i(0); i<runs_number; ++i) //Will run the simulation with the same parameters runs_number times
	{
		p->update(r);
		p->print(std::cout);
	} 
}

		
Population* Simulation::create_pop(unsigned int generation_number)
{
    struct allele
    {
        double num;
        std::string seq;
        double freq;
    };
    
    std::vector<unsigned int> marker_sites;  //vector containing the positions of the wanted nucleotides
    double N = 0;           //number of sequences = number of people.
    unsigned int A = 0;     //number of different alleles.
    std::vector<allele> population;          //vector containing the different alleles and their frequences
    
    //variables here to help the set-in
    std::string infile;
    unsigned int markersNumber, num;
    
    std::cout << "Welcome. For the simulation to begin please insert a fasta file source:\n";
    std::cin >> infile;
    
    try
    {
        std::cout << "Now please tell us how many nucleotides you are interested into:\n";
        std::cin >> markersNumber;
        if (markersNumber < 0)
        {
            throw 42;
        }
        
        std::cout << "Finally please inform us the position of the nucleotides:\n";
        for (unsigned int i = 0; i < markersNumber; ++i)
        {
            std::cin >> num;
            if (num < 0)
            {
                throw 42;
            }
            marker_sites.push_back(num);
            num.clear();
        }
    } catch (int answer)
    {
        std::cout << "Please only enter positive integers."
    }
    
    //FILE VERIFICATION STILL TO ADD
    
    std::ifstream input(infile);    //we create the stream
    if(!input.good())               //we check the file.fasta
    {
        std::cerr << "Error opening '"<<argv[1]<<"'. Bailing out." << std::endl;
        return -1;
    }
    
    //fasta reading
    //Sources: http://rosettacode.org/wiki/FASTA_format#C.2B.2B
    std::string line, name, content, sequence;
    while(std::getline(input, line).good())
    {
        if(line.empty() || line[0] == '>')//Identifier marker
        {
            if(!name.empty()) //Print out what we read from the last entry
            {
                N += 1;
                for (unsigned int i = 0; i< allelesPositions.size(); ++i)
                {
                    sequence.push_back(content[allelesPositions[i]]);
                }
                
                bool new_seq = true; //we first assume it is a new sequence then we check if we already have it in our population of alleles
                
                if (!population.empty()) //check if the vector population is empty i.e. first time
                {
                    for (unsigned int i = 0; i < population.size(); ++i)
                    {
                        if (population[i].seq == sequence) //if the sequence is the same, we add +1 to the number
                        {
                            population[i].num += 1;
                            new_seq = false;
                        }
                    }
                    if (new_seq)
                    {
                        allele a = {1, sequence};
                        population.push_back(a);
                    }
                }
                else
                {
                    allele a = {1, sequence};
                    population.push_back(a);
                }
                name.clear();
                sequence.clear();
            }
            
            if(!line.empty())
            {
                name = line.substr(1);
            }
            
            content.clear();
            
        }
        else if(!name.empty())
        {
            if(line.find(' ') != std::string::npos) //Invalid sequence--no spaces allowed (npos is the position of the last caracter)
            {
                name.clear();
                content.clear();
            } else
            {
                content += line;
            }
        }
    }
    
    //last line
    if(!name.empty())
    {
        N += 1;
        for (unsigned int i = 0; i < allelesPositions.size(); ++i)
        {
            sequence.push_back(content[allelesPositions[i]]);
        }
        bool new_seq = true; //we first assume that it's a new sequence, then we check if we already have it in our population of alleles
        
        if (!population.empty())
        {
            for (unsigned int i = 0; i < population.size(); ++i)
            {
                if (population[i].seq == sequence) //if the sequence is the same, we add +1 to the number
                {
                    population[i].num += 1;
                    new_seq = false;
                }
            }
            if (new_seq)
            {
                allele a = {1, sequence};
                population.push_back(a);
            }
        }
        else
        {
            allele a = {1, sequence};
            population.push_back(a);
        }
    }
    
    /* now the vector contains the diffents alleles; we can
     calculate the frequencies and the number of alleles
     and fill our vector containing the frequences*/
    
    A = population.size();
    std::vector<double> frequencies; //vector containing the frequencies, necessary to create a pop.
    for (unsigned int i = 0; i < population.size(); ++i)
    {
        population[i].freq = (population[i].num) / N;
        frequencies.push_back((population[i].num) / N);
    }
    
    //now we check and print everything:
    for (unsigned int i = 0; i < population.size(); ++i)
    {
        std::cout << i+1 << ") " << population[i].seq << " appeared " << population[i].num << " times. Frequency = " << population[i].freq << std::endl;
    }
    std::cout << "The number of alleles is : " << A << "\nThe total number of sequences is : " << N << std::endl;
    
    //we create the pop. to begin the simulation
    Population aWholeNewWorld(N, generations_number, A, frequencies, marker_sites);

    return aWholeNewWorld*;
}




