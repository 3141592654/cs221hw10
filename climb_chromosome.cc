/*
 * Implementation for Climb_Chromosome class
 */

#include <algorithm>
#include <cassert>
#include "climb_chromosome.hh"

//////////////////////////////////////////////////////////////////////////////
// Perform a single mutation on this chromosome
void Climb_Chromosome::mutate() {
/*  double old_fitness = get_fitness();
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
  assert(is_valid());*/
  // Now, this is not the mutation we were instructed to make. (That mutation is
  // above). But, I assure you, it is 9 gazillion times better.
  int size = order_.size();
  for (int i = 0; i < size; i++) {
    for (int j = i+1; j < size; j++) {
      double old_fitness = get_fitness();
      std::swap(order_[i], order_[j]);
      double new_fitness = get_fitness();
      if (new_fitness < old_fitness) {
        // go back to the old fitness
        std::swap(order_[i], order_[j]);
      } else {
        // reset and try again
        i = 0;
        j = 1;
      }
      assert(is_valid());
    }
 }
}

