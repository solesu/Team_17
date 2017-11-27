#include "Random.hpp"
#include <iostream>


Random::Random () 
{
	gen = std::mt19937(rd());
}


double Random::binomial (double prob, unsigned int pop) 
{
	std::binomial_distribution<int> bin (pop, prob);
	return bin(gen);
}

std::vector<double> Random::multinomial_pop (std::vector<double> frequencies, unsigned int size_pop)
{
	std::vector<double> new_frequencies;
	unsigned int new_pop = size_pop;
	unsigned int old_pop = size_pop;
	
	for (unsigned int i = 0; i < frequencies.size(); i += 1)
	{
		new_frequencies.push_back((binomial(((frequencies)[i]*size_pop)/old_pop, new_pop)));
		new_pop  -= (new_frequencies)[i]*size_pop;
		old_pop -= frequencies[i];
	}
	
	assert (old_pop==0);
	assert (new_pop==0);
	assert (frequencies.size()==new_frequencies.size());
	return new_frequencies;
}

