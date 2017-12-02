#include "Random.hpp"
#include "Population.hpp"
#include <vector>

/**
	@brief : will make migration between populations
	@param std::vector<Population*> populations: the vector of pointer on all populations in the simulation
	@param random rdm: object random to calculate random number with a discrete uniform distribution.
	@param int min_migrations: minimum number of migration
	@param int max_migrations: maximum number of migration
*/
void migration(std::vector<Population*> populations, Random rdm, int min_migrations, int max_migrations)
{
	for (int exchanges = 0; exchanges < rdm.uniform_int(min_migrations, max_migrations); exchanges++) //random number of exchange between populations
	{
		//generation of random number:
			//choose of two random population that will exchange one of their alleles.
			unsigned int pop1 = rdm.uniform_int(0, populations.size()-1); // -1 is needed to avoid the risk of seg fault as the function size() give the last place of the vector+1
			unsigned int pop2 = rdm.uniform_int(0, populations.size()-1);
			// choose of the two random places of alleles that will be exchange
			unsigned int place_allele1 = rdm.uniform_int(0, (populations[pop1]->getAlleles().size())-1);
			unsigned int place_allele2 = rdm.uniform_int(0, (populations[pop2]->getAlleles().size())-1);
			
		//memorization of the alleles 
			//memorize the 2 alleles to exchange (avoid risks of losing information if place_allele1 = place_allele2, cf exchange part just below)
			Allele allele1 = (populations[pop1]->getAlleles()[place_allele1]);
			Allele allele2 = (populations[pop2]->getAlleles()[place_allele2]);
			//exchange of the two allele
			populations[pop1]->setOneAllele(place_allele1, allele2); //give the allele2 in the place of the allele1
			populations[pop2]->setOneAllele(place_allele2, allele1); //give the allele1 in the place of the allele2
	}
}
