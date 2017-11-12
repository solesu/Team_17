#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <cmath>
#include "allele.hpp"
class population
{
	private:
	std::vector<allele*> alleles_;
	unsigned int size_; 						///size of the population 
	unsigned int generations_number_;			///number of different generation in the population
	unsigned int alleles_number_;				///number of allele s in the population
	std::vector<double> alleles_frequencies_;	///frequencies of the same  alleles
	
	
	public:
	//constructor:
	/**
	@brief : constructor for population
	@param unsigned int size: size of the population 
	@param unsigned int generations_number: number of different generation in the population
	@param unsigned int alleles_number: number of allele s in the population
	@param std::vector<double> alleles_frequencies: frequencies of the same  allele
	 */
	population(unsigned int size, unsigned int generations_number, unsigned int alleles_number, std::vector<double> frequencies);
	//getters:
	/***
	 @brief :getter for alleles_
	 @return : aleles_
	 */
	//std::vector<alleles*> getAlleles();
	/***
	 @brief :getter for size_
	 @return : size_
	 */
	unsigned int getSize();
	/***
	 @brief :getter for the number of generation 
	 @return : generation_number_
	 */
	unsigned int getGenerations_number();
	/***
	 @brief :getter for the number of alleles
	 @return : alleles_number_
	 */
	unsigned int getAlleles_number();
	/***
	 @brief :getter for alleles frequencies
	 @return : alleles_frequencies
	 */
	std::vector<double> getAlleles_frequencies();
	//setters:
	/***
	 @brief :setter for size_
	 @param unsigned int size : the size you chose
	 */
	void setSize(unsigned int size);
	/***
	 @brief :setter for the number of generations
	 @param unsigned int generation_number :the number of generations you chose
	 */
	void setGenerations_number(unsigned int generations_number);
	/***
	 @brief :setter for the number of alleles
	 @param unsigned int alleles_number: the number of alleles you want
	 */
	void setAlleles_number(unsigned int alleles_number);
};

#endif
