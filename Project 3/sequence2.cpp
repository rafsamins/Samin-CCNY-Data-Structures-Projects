// Implementation File //
// File Name: sequence2.cpp //
// Class Implemented: sequence //

#include "sequence2.h"
#include <algorithm>
#include <cassert>
using namespace std;
using namespace main_savitch_4;

namespace main_savitch_4 {
sequence::sequence(size_type initial_capacity) {
  data = new value_type[initial_capacity];
  capacity = initial_capacity;
  used = 0;
  current_index = 0;
}
// this is implementing the constructor. in our sequence2.h file, we have two
// constructors called sequence. but this is the first one and it has a
// paarameter of initial_capacity.
// data = new value type makes a new array of value_type with a size of initial
// capacity.
// capacity = initial capacity;
// used is 0 and current index is 0 because we are just initialing it here, it
// is normal to do this.

  
sequence::sequence(const sequence &source) {
  data = new value_type[source.capacity];
  capacity = source.capacity;
  used = source.used;
  current_index = source.current_index;
  copy(source.data, source.data + used, data);
}
// this is implementing the second constructor. it is also called sequence and
// is a constant reference to source. this is a copy constructor since it
// includes sequence inside the ().
// data = type new value type[source.capacity] is the same as the first, it
// allocated memory and makes an array with size of source.capacity.
// capacity = source.capacity; sets the capacity member variable to the capacity
// of the source.
// used =  source.used member variable of the new object to the used value of
// the source object current_index = source.current_index;  sets current index
// variable to the current index of the source object

  
sequence::~sequence() // the destructor
{
  delete[] data;
}
// this is implementing the destructor. it is a destructor because it is started
// with ~. its role is to delete the data array

  
void sequence::start() { current_index = 0; }
// now we can implement the member functions, implementing the member function
// start(). current_index is set to 0 because we are initializing it here. we do
// not want any errors or other numbers already in the program when we run it.

  
void sequence::advance() {
  assert(is_item());
  current_index++;
}
// this is implementing the advance function. now this checks if the user
// inputted a correct item aka a correct number or a correct input. if it is an
// item, then the index will increase. and that is what advance does. moves to
// next position essentially.

  
void sequence::insert(const value_type &entry) {
  if (used >= capacity)
    resize(1 + used + used / 10); // Increase by 10%
  if (!is_item())
    current_index = 0;
  for (size_type i = used; i > current_index; i--)
    data[i] = data[i - 1];
  data[current_index] = entry;
  used++;
}
// this is implementing the insert function. it has one parameter, entry which
// is a const pass by reference. first, we declare a variable called i because
// it will allow us to shift through elements in the array easier.
// if the used is greater than or equal to the capacity, we resize the array by
// 10%.
// if there is no item, then the current index is set to 0.
// for loop that shifts the elements in the array to the right. this makes space
// for the new element we are trying to insert.
// the number we entered is now inserted at the current index. used then
// increases as it showds the number of numbers in the sequence.
// INSERT IS BEFORE

  
void sequence::attach(const value_type &entry)
// Library facilities used: cstdlib
{

  if (used >= capacity)
    resize(1 + used + used / 10); // Increase by 10%
  if (!is_item()) {
    current_index = used;
    data[current_index] = entry;
    used++;
  } else {
    for (size_type i = used; i > (current_index + 1); i--)
      data[i] = data[i - 1];
    data[current_index + 1] = entry;
    used++;
    current_index++;
  }
}
// this is implementing the attach function. it has one parameter, entry which
// is a const pass by reference. first it makes a variable called i so it is
// easier to loop though. is used is >= capacity, we resize the array by 10%.
// now if it is NOT an item, then the current index is set to the used.	and
// whatever we entered, it now the now at the current index and used increases.
// ATTACH IS AFTER

// but if the current item IS AN ITEM then it shifts the numbers that we have to
// the right and inserts the number that we entered after the current index.
// that is why its currentindex + 1. The attach function adds a new element
// after the current_index position. Existing elements from current_index + 1 to
// the end are shifted to the right to make space for the new element.
// After attachment, the current_index is incremented to the position of the new
// element and the used counter is incremented.

  
void sequence::remove_current() {
  assert(is_item());
  for (size_type i = current_index; i < used - 1; i++)
    data[i] = data[i + 1];
  used--;
}
// this is implementing the member function called remove_current(). again i
// make a variable called i so it is easier to loop through. if the user
// inputted something that is an item. then in the for loop, we remove the
// current item and then we make the current index go to the next item. and
// since an item was deleted, used is decreased

  
void sequence::resize(size_type new_capacity) {
  value_type *larger_array;

  if (new_capacity < used)
    new_capacity = used;

  larger_array = new value_type[new_capacity];
  for (size_type i = 0; i < used; i++)
    larger_array[i] = data[i];
  delete[] data;
  data = larger_array;
  capacity = new_capacity;
}
// this is implementing the member function called resize(). it has one argument
// called new_capacity. this function relates to the attach and insert functions
// because it is resizing. first i make a variable called i to loop easier.
// largerarray is a pointer to a new array of value_type. if the newcapacity is
// less than the number of elements we have, then theyre equal.

// now largerarray is a new array of value_type with a size of new_capacity. the
// for loop is essentially copying elements from the array i have to the new
// largerarray. it then deletes the old array elements. and then sets the data
// to the new array. and the capacity to the new capacity.

  
sequence::size_type sequence::size() const { 
  return used; 
}
// this is implementing the size() function. it returns the used member
// variable. because size is essentially how many items are in the seuqnece and
// used is the number of items in the sequence.

  
bool sequence::is_item() const { 
  return (current_index < used); 
}
// this is implementing the is_item() function. it returns true if the current
// index is less than used. and false/0 otherwise

  
sequence::value_type sequence::current() const {
  assert(is_item());
  return data[current_index];
}
// this is implementing the current() function. if it is an item. then it
// returns the number at the current index.



  

// ----------------------------------------------------------------------- //
// OPERATOR OVERLOADING CONST MEMBER FUNCTIONS ARE BELOW //

void sequence::operator=(const sequence &source) {
  value_type *new_data;

  if (capacity != source.capacity) {
    new_data = new value_type[source.capacity];
    delete[] data;
    data = new_data;
    capacity = source.capacity;
  }
  used = source.used;
  current_index = source.current_index;
  for (size_type i = 0; i < used; i++)
    data[i] = source.data[i];
}
// this is now implementing the operator=() function. it has one argument called
// source and is a const pass by reference. i then make a variable called i and
// then a pointer called new data.

// if the capacity is not equal to the source capacity, then we make a new
// array. as shown by line 199. and then we delete the existing array. and then
// points data to new data to reallocate the memory. and then capacity matches
// source capacity.

// next, is the copy operattion. it then copies elements from the source to the
// sequence. it sets used equal to the source used. and current index to match
// source.currentindex. it then copies all of the elements from source data to
// data

  
void sequence::operator+=(const sequence &source) {
  if (used + source.used > capacity)
    resize(used + source.used);

  copy(source.data, source.data + source.used, data + used);
  used += source.used;
  current_index = (used - 1);
}
// this is implementing the operator+=() function. it has one argument called
// source. it is a const pass by reference. this concatenates the elements of
// another sequence to the end of the current sequence. is used plus the size of
// the source is greater than the capacity, then it resizes to make room for
// additional elements.

// it then copies elements from source.data to the current data array starting
// from data + used.
// source.data: pointer to beginning of array
// source.data + source.used: pointer to one past the last element
// data + used: pointer to the position in the current sequences data array

  
sequence operator+(const sequence &source1, const sequence &source2) {
  sequence source3(source1.size() + source2.size());
  source3 += source1;
  source3 += source2;
  return source3;
}
// this is implementing the operator+() function. it has two arguments called
// source1 and source2. it is a const pass by reference. this is also
// concatenating two sequences and then makes a new one called source3 that
// contained elements from both.

  
sequence::value_type sequence::operator[](size_type index) const {
  assert(index < used);
  return data[index];
}
// this is implementing the operator[] function. it has one argument called
// index of data type size_t. it makes sure by assert that index is less than
// used and if it is, it then returns the data at the index. this allows us to
// essentially access elements.
}
