#include "Simulation.hpp"

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

		
Population* Simulation::create_pop(unsigned int generation_number, std::vector<unsigned int> marker_sites)
{
    double N = 0;           //total number of sequences = number of people.
    unsigned int A = 0;     //number of different alleles.
    std::vector<Allele> population; //vector containing the different alleles and their frequences
    
    //variables here to help the set-in
    std::string infile;
    
    std::cout << "Welcome. For the simulation to begin please insert a fasta file source:\n";
    std::cin >> infile;
    
    //FILE VERIFICATION STILL TO ADD
    
    std::ifstream input(infile); //we create the stream
    try
	{	
		if(!input.is_open()) //we check the file.fasta
		{
			throw 42;
		}
	}
	catch (int answer)
	{
		std::cerr << "Error opening '"<< infile <<"'. Bailing out." << std::endl;
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
                for (unsigned int i = 0; i < marker_sites.size(); ++i)
                {
                    //check in case there is a mistake inside the nuclotides sequence
                    if (content[pos[i]] == 'a' or content[pos[i]] == 'A' or
                        content[pos[i]] == 't' or content[pos[i]] == 'T' or
                        content[pos[i]] == 'g' or content[pos[i]] == 'G' or
                        content[pos[i]] == 'c' or content[pos[i]] == 'C')
                    {
                        sequence.push_back(content[marker_sites[i]]);
                    }
                    else
                    {
                        int random_number = rand() % 4; //generates a pseudo random number between 0 and 4
                        switch (random_number)
                        {
                            case 0:
                                sequence.push_back('A');break;
                            case 1:
                                sequence.push_back('T');break;
                            case 2:
                                sequence.push_back('G');break;
                            case 3:
                                sequence.push_back('C');break;
                        }
                    }
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
                        Allele a = {1, sequence};
                        population.push_back(a);
                    }
                }
                else
                {
                    Allele a = {1, sequence};
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
        for (unsigned int i = 0; i < marker_sites.size(); ++i)
        {
            //check in case there is a mistake inside the nuclotides sequence
            if (content[pos[i]] == 'a' or content[pos[i]] == 'A' or
                content[pos[i]] == 't' or content[pos[i]] == 'T' or
                content[pos[i]] == 'g' or content[pos[i]] == 'G' or
                content[pos[i]] == 'c' or content[pos[i]] == 'C')
            {
                sequence.push_back(content[marker_sites[i]]);
            }
            else
            {
                int random_number = rand() % 4; //generates a pseudo random number between 0 and 4
                switch (random_number)
                {
                    case 0:
                        sequence.push_back('A');break;
                    case 1:
                        sequence.push_back('T');break;
                    case 2:
                        sequence.push_back('G');break;
                    case 3:
                        sequence.push_back('C');break;
                }
            }
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
                Allele a = {1, sequence};
                population.push_back(a);
            }
        }
        else
        {
            Allele a = {1, sequence};
            population.push_back(a);
        }
    }
    
    input.close();
    
    /*now the vector contains the diffents alleles; we can
     calculate the frequencies and the number of alleles
     and fill our vector containing the frequences*/
    
    A = population.size();
    std::vector<double> frequencies; //vector containing the frequencies, necessary to create a pop.
    for (unsigned int i = 0; i < population.size(); ++i)
    {
        population[i].frequency = (population[i].num) / N;
        frequencies.push_back((population[i].num) / N);
    }
    
    //now we check and print everything:
    for (unsigned int i = 0; i < population.size(); ++i)
    {
        std::cout << i+1 << ") " << population[i].seq << " appeared " << population[i].num << " times. Frequency = " << population[i].frequency << std::endl;
    }
    std::cout << "The number of alleles is : " << A << "\nThe total number of sequences is : " << N << std::endl;
    
    //we create the pop. to begin the simulation
    return new Population (population,N, generation_number, A, frequencies);    
}
