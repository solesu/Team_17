#include "Random.hpp"


Random::Random () 
{
	gen = std::mt19937(rd());
}




int Random::binomial (double prob, unsigned int pop) 
{
	std::binomial_distribution<int> bin (pop, prob);
	return bin (gen);
}




std::vector<double> Random::multinomial_pop (std::vector<double>* frequencies, unsigned int size_pop)
{
	std::vector<double> result;
	unsigned int new_pop = size_pop;
	unsigned int old_pop = size_pop;
	
	for (unsigned int i = 0; i < frequencies->size(); i += 1)
	{
		result.push_back((binomial(((*frequencies)[i]*size_pop)/old_pop, new_pop))/size_pop);
		new_pop  -= (*frequencies)[i]*size_pop;
		old_pop -= result[i];
	}

	return result;
}




int Random::uniform(int value)
{
	std::uniform_int_distribution<unsigned int> uni (0, value);
	return uni(gen);
}
