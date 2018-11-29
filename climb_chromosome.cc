/*
 * Implementation for Climb_Chromosome class
 */

#include <algorithm>
#include <cassert>
#include <iostream>  // REMOVE ME

#include "climb_chromosome.hh"

//////////////////////////////////////////////////////////////////////////////
// Perform a single mutation on this chromosome
void Climb_Chromosome::mutate() {
  std::cout << "Stuff from climb_chromosome is running!\n";
  double old_fitness = get_fitness();
  static std::uniform_int_distribution<int> dist(0, order_.size() - 1);
  int p = dist(generator_);
  // make sure p-1 doesn't equal -1
  int p_minus_one = (p-1) % order_.size();
  std::swap(order_[p], order_[p_minus_one]);
  double new_fitness = get_fitness();
  if (new_fitness < old_fitness) {
    // go back to the old fitness
    std::swap(order_[p], order_[p_minus_one]);
  }
  assert(is_valid());
}


