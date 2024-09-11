// FILE: sequence1.cpp
// CLASS IMPLEMENTED: sequence

#include "sequence1.h"
#include <cassert> // Provides assert
using namespace std;

namespace main_savitch_3 {
// CONSTRUCTOR for sequence class
sequence::sequence() {
  used = 0;
  current_index = 0;
}
// implementing the constructor that we have. the constructor is called sequence
// and it was a default constructor in sequence1.h. we are initializing used and
// current_index to 0 so no errors or wrong calculations occur when we run the
// program. this is a common thing to do.

void sequence::start() { current_index = 0; }
// now here, I am implementing the member functions now. implementing member
// functions is class name::function name. we set the current_index = 0 because
// when we want to start the sequence, we want to start at the beginning. if we
// do not do this, the program will not work and then it can essentially start
// it anywhere.

void sequence::advance() {
  if (is_item())
    current_index++;
  else {
    return;
  }
}
// implementing the member function called advance. this makes sure that the
// user input is valid and the current item is valid. once it is valid, then it
// will go to the next index. if the index is not valid then it will

void sequence::insert(const sequence::value_type &entry) {
  if (size() < CAPACITY) {
    if (!is_item())
      current_index = 0;
    for (size_type i = used; i > current_index; i--)
      data[i] = data[i - 1];
    data[current_index] = entry;
    used++;
  }
}
// implementing the member function called inserrt. takes the argument of
// value_type and the member variable (which is why I do sequence::value_type).
// takes a const reference and pass by reference of entry.
//
// size is a constant member function. if size is less than CAPACITY, and it
// isnt an item, then the current index is set to 0. and then the current index
// of the data is set to user entry. and as we continue thru the program, it
// will increment used. (used is a private member var)

void sequence::attach(const sequence::value_type &entry) {
  if (size() < CAPACITY) {
    if (!is_item()) {
      current_index = used - 1;
    }
    for (int i = used; i > (current_index + 1); i--)
      data[i] = data[i - 1];
    data[current_index + 1] = entry;
    current_index++;
    used++;
  }
}
// now implementing the member function attach, it takes one argument , a
// constant reference to value_type which is an alias for entry. attach takes a
// reference to a value type from sequence and it it constant so it doesnt
// change the value of entry.

// the if statement is similar to the insert function. however, we do current
// index = used - 1 because attach is after. and insert is before. so if there
// isn't an item, then the current index is set to used - 1. and the for loop,
// shifts the numbers that we have to the right.

sequence::value_type sequence::current() const {
  if (is_item())
    return data[current_index];
  else {
    return 0;
  }
}
// now implementing the current function. if there is an item, then we return
// data of the current index. it checks if its a real item. if it is not, then
// return.

void sequence::remove_current() {
  if (is_item()) {
    for (int i = current_index; i < (used - 1); i++) {
      data[i] = data[i + 1];
    }
    used--;
  }
}

sequence::size_type sequence::size() const {
  return used;
}

bool sequence::is_item() const {
  return current_index < used;
}
} // namespace main_savitch_3
