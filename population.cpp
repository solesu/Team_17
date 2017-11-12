#include <iostream>
#include "population.hpp"
#include <cmath>
#include <random>

	population::population(unsigned int size, unsigned int generations_number, unsigned int alleles_number, std::vector<double> frequencies)
	{}
	//getters:
	
	std::vector<alleles*> getAlleles()
	{
		return alleles_;
	}

	unsigned int population::getSize()
	{
		return size_;
	}
	
	unsigned int population::getGenerations_number()
	{
		return generations_number_;
	}
	unsigned int population::getAlleles_number()
	{
		return alleles_number_;
	}
	std::vector<double> population::getAlleles_frequencies()
	{
		return alleles_frequencies_;
	}
	//setters:
	
	void population::setSize(unsigned int size)
	{
		size_=size;
	}
	
	
	void population::setGenerations_number(unsigned int generations_number)
	{
		generations_number_= generations_number;
	}
	
	void population::setAlleles_number(unsigned int alleles_number)
	{
		alleles_number_ = alleles_number;
	}


