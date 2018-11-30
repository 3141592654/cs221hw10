/*
 * Extension of the Deme class (see deme.hh). Implements tournament selection.
 */

#pragma once

#include <random>
#include "climb_chromosome.hh"
#include "cities.hh"
#include "deme.hh"

class Tournament_Deme: public Deme {
 public:
  Tournament_Deme(const Cities* cities_ptr, unsigned pop_size, double
             mut_rate) : Deme::Deme(cities_ptr, pop_size, mut_rate) {
    for (P = 2; P * 6 < pop_.size(); P *=2) {}
  }

 protected:
  // Select the new parent by picking P parents and picking the fittest one.
  Chromosome* select_parent();
  unsigned P;
};
