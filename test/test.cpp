#include <gtest/gtest.h>
#include "../source/Simulation.hpp"
#include "../source/Population.hpp"
#include "../source/Random.hpp"


/*TEST (SimulationTest, tclap)
{
	Simulation s;
	int argc;
	char** argv;
	Population* pop(s.parse_args(argc, argv)); 
}*/

TEST (PopulationTest, constructionGetterSetter)
{
	std::vector<double> frequencies({0.2,0.8});
	Population* pop = new Population(100,3000,2, frequencies); 
	EXPECT_EQ(pop->getSize(),100);
	EXPECT_EQ(pop->getGenerations_number(),3000);
	EXPECT_EQ(pop->getAlleles_number(),2);
	EXPECT_EQ(pop->getAlleles_frequencies(),frequencies);
	pop->setSize(1000);
	EXPECT_EQ(pop->getSize(),1000);
	pop->setGenerations_number(1000);
	EXPECT_EQ(pop->getGenerations_number(),1000);
	pop->setAlleles_number(3);
	EXPECT_EQ(pop->getAlleles_number(),3);
	
}

TEST (RandomTest, Multinomiale)
{
	Random r;
	double count(0);
	std::vector<double> frequencies({0.2,0.8});
	std::vector<double> new_frequencies(r.multinomial_pop(frequencies, 10));
	for(unsigned int i(0); i<new_frequencies.size(); ++i){
		count+=new_frequencies[i];
	}
	EXPECT_EQ(count, 1);
}



int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


