#ifndef POPULATION_HPP
#define POPULATION_HPP
#include <vector>
#include <cmath>
#include <iomanip>
#include "Allele.hpp"
#include "Random.hpp"

class Population
{
	private:
	std::vector<Allele> alleles_;				///< vector containing the different type of alleles
	std::vector<double> alleles_frequencies_;	///<frequencies of the same  alleles
	unsigned int size_; 						///<size of the population 
	unsigned int generations_number_;			///<number of different generation in the population
	unsigned int alleles_number_;				///<number of allele s in the population

	
	
	public:
	//Constructor and destructor
	/**
	@brief : constructor for population
	@param unsigned int size: size of the population 
	@param unsigned int generations_number: number of different generation in the population
	@param unsigned int alleles_number: number of allele s in the population
	@param std::vector<double> alleles_frequencies: frequencies of the same  allele
	 */
	Population(std::vector<Allele> alleles, unsigned int size, unsigned int generations_number, unsigned int alleles_number, std::vector<double> frequencies);
	/** 
	 * @brief Destructor of Population
	 * Delete alleles_ which contains pointers
	 */
	~Population();
	
	//Getters:
	/***
	 @brief :getter for alleles_
	 @return : aleles_
	 */
	std::vector<Allele> getAlleles() const;
	/***
	 @brief :getter for size_
	 @return : size_
	 */
	unsigned int getSize() const;
	/***
	 @brief :getter for the number of generation 
	 @return : generation_number_
	 */
	unsigned int getGenerations_number() const;
	/***
	 @brief :getter for the number of alleles
	 @return : alleles_number_
	 */
	unsigned int getAlleles_number() const;
	/***
	 @brief :getter for alleles frequencies
	 @return : alleles_frequencies
	 */
	std::vector<double> getAlleles_frequencies() const;
	
	//Setters:
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
	
	//update:
	/***
	@brief : will update for each generation the alleles frequencies
	@param random r: object random to calculate the multinomial distribution for the new frequencies.
	@param unsigned int generation : the new generation.
	*/
	void update(Random& r);	
	/***
	@brief : print the frequencies of each generation for each replicate in the desired fromat
	@param ostream& ouput 
	*/
	void print(std::ostream& output) const;
	

};

#endif
