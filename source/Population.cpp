#include "Population.hpp"
#include <iostream>
#include <cmath>
#include <random>


	//Constructor and destructor
	Population::Population(unsigned int size, unsigned int generations_number, unsigned int alleles_number, std::vector<double> frequencies)
	:size_(size), generations_number_(generations_number), alleles_number_(alleles_number), alleles_frequencies_(frequencies)
	{}
	
	Population::~Population()
	{
		for(unsigned int i(0); i< alleles_.size(); ++i)
		{
			delete alleles_[i];
		}
		alleles_.clear();
	}
	
	//Getters:
	std::vector<Allele*> Population::getAlleles() const
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
	
	//Setters:
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
	
	//update:
	void Population::update(unsigned int generation, Random r)
	{
		//update frequencies for each generation:
		alleles_frequencies_= (r.multinomial_pop(alleles_frequencies_*, size_));
		generations_number_ = generation;
	}

