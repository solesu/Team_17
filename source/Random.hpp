#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <iostream>
#include <cassert>

class Random {
	
	private:
	 std::random_device rd;   ///<Definition of the random device.
	 std::mt19937 gen;   ///<Generator of random numbers.
	
	public:
	///@brief : Constructor
	///It creates the generator of random numbers. 
	Random ();
	
	///@brief : Simulation of a binomial distribution.
	///@param prob : probability of the event
	///@param pop : size of the population
	double binomial (double prob, unsigned int pop);
	
	///@brief : Simulation of the multinomial distribution applied to the population.
	///@param frequencies : vector of the frequencies of the alleles in the population
	///@param total_pop : total population  
	std::vector<double> multinomial_pop(std::vector<double> frequencies, unsigned int size_pop);
	
	///@brief : Simulation of a uniform distribution
	///@param value : maximum value of the distribution
	int uniform (int value);	
};

#endif
