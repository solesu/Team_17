#include <iostream>
#include "population.hpp"
#include <cmath>
#include <random>

	Population::Population(unsigned int size, unsigned int generations_number, unsigned int alleles_number, std::vector<double> frequencies)
	:size_(size), generations_number_(generations_number), alleles_number_(alleles_number), alleles_frequencies_(frequencies)
	{}
	//getters:
	
	std::vector<alleles*> Population::getAlleles() const
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
	unsigned int Population::getAlleles_number() const
	{
		return alleles_number_;
	}
	std::vector<double> Population::getAlleles_frequencies() const
	{
		return alleles_frequencies_;
	}
	//setters:
	
	void Population::setSize(unsigned int size)
	{
		size_=size;
	}
	
	
	void Population::setGenerations_number(unsigned int generations_number)
	{
		generations_number_= generations_number;
	}
	
	void Population::setAlleles_number(unsigned int alleles_number)
	{
		alleles_number_ = alleles_number;
	}


