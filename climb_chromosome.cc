/*
 * Implementation for Climb_Chromosome class
 */

#include <algorithm>
#include <cassert>
#include "climb_chromosome.hh"

//////////////////////////////////////////////////////////////////////////////
// Perform a single mutation on this chromosome
void Climb_Chromosome::mutate() {
  // climb_hill() is not what is specified in the prompt, but does dramatically
  // improve the performance of the algorithm. If you want to see it, uncomment
  // it. The rest of the function is the solution specified in the prompt, so
  // comment that also.
  // climb_hill();

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

void Climb_Chromosome::climb_hill() {
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
  static std::uniform_real_distribution<double> dist(0.0, 1.0);
  double d = dist(generator_);
  // really, of course, this should be what happens in mutate. But to really go
  // down the hill-climbing path, the deme class (among others) should be
  // scrapped altogether.
  if (d <= 0.10) {
     order_ = random_permutation(order_.size());
  }
  assert(is_valid());
}

