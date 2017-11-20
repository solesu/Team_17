#include <iostream>
#include <fstream>
#include <vector>

struct allele 
{
  double num; //number of people with this allele
  std::string seq; //the allele sequence
  double freq; //frequence of the allele
};

//g++ rosettacode.cpp -o test.exe
//test.exe rosetta.fasta

int main(int argc, char** argv)
{
    // first, we initilize a vector of the position of the nucleotides we are going to focus on.
    // the positions of the nucleotides should be given by the user 
    // SEE THAT LATER
    std::vector<unsigned int> allelesPositions = {0,2,3,4};
    
    double N = 0; // number of sequences = number of people
    unsigned int A = 0; // number of different alleles
    
    std::vector<allele> population; // table of the different alleles

    if(argc <= 1) //Explain the correct usage of the program
    {
        std::cerr << "You should write: "<<argv[0]<<" [file.fasta]" << std::endl;
        return -1;
    }

    std::ifstream input(argv[1]); //we create the stream
    if(!input.good()) //we check the file.fasta
    {
        std::cerr << "Error opening '"<<argv[1]<<"'. Bailing out." << std::endl;
        return -1;
    }

    std::string line, name, content, sequence;
    while(std::getline(input, line).good()) 
    {
		if(line.empty() || line[0] == '>')// Identifier marker
        {
			if(!name.empty()) // Print out what we read from the last entry
            { 
                //std::cout << name << " : " << content << std::endl;
                N += 1;
                for (unsigned int i = 0; i< allelesPositions.size(); ++i)
                {
					sequence.push_back(content[allelesPositions[i]]);
                }
                
                bool new_seq = true; // we first assume it is a new sequence then we check if we already have it in our population of alleles
                
                if (!population.empty()) // check if the vector population is empty i.e. first time
                { 
					for (unsigned int i = 0; i < population.size(); ++i)
					{
						if (population[i].seq == sequence) // if the sequence is the same, we add +1 to the number
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
            if(line.find(' ') != std::string::npos) // Invalid sequence--no spaces allowed (npos is the position of the last caracter)
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
		bool new_seq = true; // we first assume that it's a new sequence, then we check if we already have it in our population of alleles
		
		if (!population.empty())
		{ 
			for (unsigned int i = 0; i < population.size(); ++i)
			{
				if (population[i].seq == sequence) // if the sequence is the same, we add +1 to the number
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
   
    // now the vector contains the diffents alleles; we can
    // calculate the frequencies and the number of alleles
    A = population.size();
    for (unsigned int i = 0; i < population.size(); ++i)
    {
		population[i].freq = (population[i].num) / N;
    }
    
    //now we check and print everything:
    for (unsigned int i = 0; i < population.size(); ++i)
    {
		std::cout << i+1 << ") " << population[i].seq << " appeared " << population[i].num << " times. Frequency = " << population[i].freq << std::endl;
    }
    std::cout << "The number of alleles is : " << A << "\nThe total number of sequences is : " << N << std::endl;

    return 0;
}
