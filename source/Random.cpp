#include "Random.hpp"


Random::Random () : gen(rd())
{
}




int Random::binomial (double prob, int pop) 
{
	std::binomial_distribution<int> bin (pop, prob);
	return bin (gen);
}




std::vector<double> Random::multinomial_pop (std::vector<double>* frequencies, int total_pop)
{
	std::vector<double> result;
	int new_pop = total_pop;
	int old_pop = total_pop;
	
	for (unsigned int i = 0; i < frequencies->size(); i += 1)
	{
		result.push_back((binomial(((*frequencies)[i]*total_pop)/old_pop, new_pop))/total_pop);
		new_pop  -= (*frequencies)[i]*total_pop;
		old_pop -= result[i];
	}

	return result;
}




int Random::uniform(int value)
{
	std::uniform_int_distribution<int> uni (0, value);
	return uni(gen);
}
