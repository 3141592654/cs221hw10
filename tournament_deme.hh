/*
 * Extension of the Deme class (see deme.hh). Implements tournament selection.
 */

#pragma once

#include "climb_chromosome.hh"
#include "cities.hh"
#include "deme.hh"
#include <random>
#include <iostream>  //REMOVE ME


class Tournament_Deme: public Deme {
 public:
  // not much overriding in the constructor, but I wanted to only calculate
  // P once.
//   using Deme::Deme;
  Tournament_Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
    : Deme::Deme(cities_ptr, pop_size, mut_rate) {std::cout << "tournament deme"
      <<"is being constructed\n";
      std::cout << "i am a tournament deme, was passed pop size of " << pop_size << "\n";
      std::cout << "i now have a pop size of " << pop_.size() << "\n"; 
    };
// using Deme::~Deme;
//using Deme::compute_next_generation;




 protected:
  // ADD DESCRIPTION
  Chromosome* select_parent();  //VIRTUALNESS HERE SHOULDN'T MATTER
//  unsigned P;

  // OTHER PROTECTED STUFF FROM DEME
//    std::vector<Climb_Chromosome*> pop_;  // Population of Chromosomes
/*  double mut_rate_;  // Mutation rate (fraction in range [0,1])

  std::default_random_engine generator_; // A random number generator for the various methods
*/
};
