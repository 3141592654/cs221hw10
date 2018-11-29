/*
 * Implementation for Tournament_Deme class
 */


#include "climb_chromosome.hh"
#include "cities.hh"
#include "tournament_deme.hh"
#include <random>
#include <iostream> // REMOVE ME

/*Deme::Deme(const Cities* cities_ptr, unsigned pop_size,
      double mut_rate): pop_(pop_size), mut_rate_(mut_rate) {
  // Create random Climb_Chromosomes and put into population vector
  for (auto& cp : pop_) {
    cp = new Climb_Chromosome(cities_ptr);
  }
  // Taken from my solution. Seed the random number generator with 6*9||0.
  generator_ = std::default_random_engine(420);
  // The only bit which is different than Deme.
  for (P = 2; P * 6 < pop_size; P *=2);
  std::cout << "tournament deme being constructed\n";
}*/


Climb_Chromosome* Tournament_Deme::select_parent() {
  // WHY CAN'T WE JUST READ IN P CHROMOSOMES AND STORE THE BEST FOUND? IT WILL
  // USE UP LESS MEMORY AND IS SIMPLER...
  // Create a tournament pool with P random parents
  unsigned P;
    for (P = 2; P * 6 < pop_.size(); P *=2);  // IDAELLY DO THIS ONLY ONCE. BUT
    //FOR NOW, THERE ARE BIGGER FISH TO FRY.

  std::vector<Climb_Chromosome*> tournamentPool;
  tournamentPool = std::vector<Climb_Chromosome*>(0);
  for (unsigned i = 0; i < P; i++) {
    static std::uniform_int_distribution<int> dist(0, pop_.size()-1);
    tournamentPool.push_back(pop_[dist(generator_)]);
  }
  // eliminate tournament chromosomes until there is only one left
  for (int size = tournamentPool.size(); size > 1; size=tournamentPool.size()) {
    // say i = 0. the 0th and 1st chromosomes stage a brutal fight to the
    // death. the loser gets erased. the chromosome which used to be the 2nd
    // is now the 1st. compare that choromosome to the 2nd, which was previously
    // known as the 3rd. keep going in this way until half of the chromosomes
    // get erased.
    for (int i = 0; i < size/2; i++) {
      if (tournamentPool[i]->get_fitness() < tournamentPool[i+1]->get_fitness()) {
        tournamentPool.erase(tournamentPool.begin()+i);
      } else {
        tournamentPool.erase(tournamentPool.begin()+i+1);
       }
    }
  }
  // P chromosomes enter, 1 chromosome leaves.
  return tournamentPool[0];
}


