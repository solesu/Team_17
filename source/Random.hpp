#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <random>


class Random {
	
	private :
	
	static std::random_device rd;   ///<Definition of the random device.
	std::mt19937 gen;   ///<Generator of random numbers.
	
	
	public:
	
	///@brief : Constructor
	///It creates the generator of random numbers. 
	Random ();
	
	
	///@brief : Simulation of a binomial distribution.
	///@param prob : probability of the event
	///@param pop : size of the population
	int binomial (double prob, int pop);
	
	
	///@brief : Simulation of the multinomial distribution applied to the population.
	///@param frequencies : vector of the frequencies of the alleles in the population
	///@param total_pop : total population  
	std::vector<double> multinomial_pop (std::vector<double>* frequencies, int total_pop);
	
	
	///@brief : Simulation of a uniform distribution
	///@param value : maximum value of the distribution
	int uniform (int value);
	
};


#endif