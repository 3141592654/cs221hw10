/*
 * Extension of the Chromosome class (see chromosome.hh). Implements local
 * hill-climbing for its mutation.
 */

#pragma once

#include "cities.hh"
#include "chromosome.hh"
#include <random>

class Climb_Chromosome: public Chromosome {
  // THIS SHOULDN'T BE NEEDED
/*  Climb_Chromosome(const Climb_Chromosome&) = delete;
  Climb_Chromosome(Climb_Chromosome&&) = delete;
  Climb_Chromosome& operator=(const Climb_Chromosome&) = delete;
  Climb_Chromosome& operator=(Climb_Chromosome&&) = delete;*/

 public:
  // Creation method for new Chromsomoe. Saves a copy of the cities and
  // generates a completely random permutation from a list of cities.
//Climb_Chromosome(const Cities*);
   using Chromosome::Chromosome;//(const Cities*);
/*

  public:*/
  // Polymorphic creation method from an existing Chromosome.
  // This method allocates memory for the newly created chromosome.
  // It is the caller's responsibility to free this memory.
  Chromosome* clone() const {
    //DOES THIS NEED TO BE OVERRIDDEN? PROMPT SAYS WE WILL BUT PROVIDES NO
    //INSTRUCTIONS ON HOW TO DO SO...
    return new Climb_Chromosome(cities_ptr_);
  }

  // Perform a single mutation on this chromosome
  void mutate();
};
