/*
 * Extension of the Chromosome class (see chromosome.hh). Implements local
 * hill-climbing for its mutation.
 */

#pragma once

#include <random>
#include "cities.hh"
#include "chromosome.hh"

class Climb_Chromosome: public Chromosome {
 public:
  // Creation method for new Chromsomoe. Saves a copy of the cities and
  // generates a completely random permutation from a list of cities.
  using Chromosome::Chromosome;

  // Polymorphic creation method from an existing Chromosome.
  // This method allocates memory for the newly created chromosome.
  // It is the caller's responsibility to free this memory.
  Chromosome* clone() const {
    return new Climb_Chromosome(cities_ptr_);
  }

  // Perform a single mutation on this chromosome
  void mutate();

  // Finds a relatively good path by climbing hills.
  void climb_hill();
};
