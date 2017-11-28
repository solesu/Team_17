#include "Population.hpp"


//Constructor and destructor
Population::Population(std::vector<Allele> alleles, unsigned int size, unsigned int generations_number,std::vector<double> frequencies)
: alleles_(alleles), size_(size), generations_number_(generations_number), alleles_frequencies_(frequencies)
{
	Random r;
	for (unsigned int i(0); i<alleles_.size(); ++i)
	{
		fitness_.push_back(r.uniform_real(-1,1)); 
		if(fitness_.back()==-1){
			lethal_selection(i);
		}
	}
}
	
Population::~Population()
{}
	
//Getters:
std::vector<Allele> Population::getAlleles() const
{
	return alleles_;
}

unsigned int Population::getSize() const
{
	return size_;
}
	
unsigned int Population::getGenerations_number() const
{
	return generations_number_;
}

	
std::vector<double> Population::getAlleles_frequencies() const
{
	return alleles_frequencies_;
}
	
//Setters:
void Population::setSize(unsigned int size)
{
	size_=size;
}
	
	
void Population::setGenerations_number(unsigned int generations_number)
{
	generations_number_= generations_number;
}
	
	
//update:
void Population::update(Random& r)
{
	double sum_fitness(0);
	for(unsigned int i(0); i<alleles_frequencies_.size(); ++i)
	{
		sum_fitness+=alleles_frequencies_[i]*size_*fitness_[i];
	}
	sum_fitness/=size_;
	
	for(unsigned int i(0); i<alleles_frequencies_.size(); ++i)
	{
		alleles_frequencies_[i]=(alleles_frequencies_[i])*(1+fitness_[i]/(1+sum_fitness));
	}
	//update frequencies for each generation taking into consideration the selection factor:
	alleles_frequencies_= (r.multinomial_pop(alleles_frequencies_, size_));

}

void Population::print(std::ostream& output) const
{
	output << "\t"; 
	for (size_t i (0); i < alleles_frequencies_.size(); ++i)
	{
		output << std::fixed << std::setprecision(3) << alleles_frequencies_[i] << "|";
	}
}

void Population::lethal_selection(unsigned int index)
{
	size_=size_*(1-alleles_frequencies_[index]);
	alleles_.erase(alleles_.begin()+index);
	alleles_frequencies_.erase(alleles_frequencies_.begin()+index);
	
}
