/*
 * Implementation for Tournament_Deme class
 */


#include "climb_chromosome.hh"
#include "cities.hh"
#include "tournament_deme.hh"
#include <random>

Chromosome* Tournament_Deme::select_parent() {
  // Create a tournament pool with P random parents
  std::vector<Chromosome*> tournamentPool;
  tournamentPool = std::vector<Chromosome*>(0);
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

