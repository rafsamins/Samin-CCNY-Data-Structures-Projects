// FILE: stats.cpp
// CLASS IMPLEMENTED : statistician
#include "stats.h"
#include <cassert>        //Provides Assert
namespace main_savitch_2C // Provides stats definition
{
statistician::statistician()
// //implementing the member function here. class is statistician followed by ::
// and then function name
{
  count = 0;
  total = 0;
} // initializing count and total to 0 so there isnt any errors in terms of
  // calculation when we run the file
void statistician::next(double r)
// stores numbers
{
  if (count == 0) {
    tinyest = r;
    largest = r;
  }
  count++;
  total = total + r;
  if (r > largest)
    largest = r;
  if (r < tinyest)
    tinyest = r;
}
// if count is 0 then it will set the tinyest and largest to the first number.
// it then increments the value of count because of the ++. once it increments,
// it adds to the total and then updates if the number is larger than the
// largest or smaller than the tinyest.

void statistician::reset() {
  count = 0;
  total = 0;
}
// as the name suggests, it resets the count and total to 0

int statistician::length() const { return count; }
double statistician::sum() const { return total; }
double statistician::mean() const {
  assert(count > 0);
  return (total / count);
}
double statistician::minimum() const {
  assert(count > 0);
  return tinyest;
}

double statistician::maximum() const {
  assert(count > 0);
  return largest;
}

// this is all implementing the member functions. in stats.h, we have length,
// sum, mean, min, max as our const member functions. here we keep them all as
// const. and for length we return count because we want to return how many have
// been passed. and for sum, we return total because we want to return the sum
// of all the numbers. for mean, we return total/count. because mean is just all
// the numbers added up and divided by the amount of numbers. for min, return
// tiny. for max, return largest.

statistician operator+(const statistician &s1, const statistician &s2) {
  statistician s3;

  if (s1.count == 0) {
    s3.tinyest = s2.tinyest;
    s3.largest = s2.largest;
  }
  if (s2.count == 0) {
    s3.tinyest = s1.tinyest;
    s3.largest = s1.largest;
  }
  if (s1.count > 0 && s2.count > 0) {
    if (s1.tinyest < s2.tinyest)
      s3.tinyest = s1.tinyest;
    else
      s3.tinyest = s2.tinyest;
    if (s1.largest > s2.largest)
      s3.largest = s1.largest;
    else
      s3.largest = s2.largest;
  }

  s3.total = s1.total + s2.total;
  s3.count = s1.count + s2.count;
  return s3;
}
// this is the operator+ function. in stattest.cpp, we are given s1, s2, and s3.
// for this, takes a constant reference to s1 and s2 and creates new object s3.
// if count is 0, meaning empty, then s3 will have the same values for tiny and
// largest as s1 or s2. but if count is not 0, then will compare it and set the
// value accordingly.

statistician operator*(double scale, const statistician &s) {
  statistician s3;
  if (scale > 0) {
    s3.tinyest = s.tinyest * scale;
    s3.largest = s.largest * scale;
  } else {
    s3.tinyest = s.largest * scale;
    s3.largest = s.tinyest * scale;
  }
  s3.total = s.total * scale;
  s3.count = s.count;
  return s3;
}
// this is the operator* function. in stattest.cpp, we are given s1, s2, and s3.
// for this, it checks the multiplication now. it takes scale and a constant
// reference to s. if scale is greater than 0, then it will multiply the tinyest
// and largest by the scale (we have scale and s from the friend function in
// stats.h) again, it initializes s3 and if scale is greater than 0, it
// multiples the tiny and large by scale. or it multiplies the tiny and large by
// scale.

bool operator==(const statistician &s1, const statistician &s2) {
  if (s1.length() == 0 && s2.length() == 0)
    return true; // could also do return 1. if we do return 0, test 5 will fail
  return (s1.length() == s2.length()) && (s1.sum() == s2.sum()) &&
         (s1.mean() == s2.mean()) && (s1.minimum() == s2.minimum()) &&
         (s1.maximum() == s2.maximum());
}
// this is the operator== function. in stattest.cpp, we are given s1, s2, and
// s3. but here we are focusing on s1 and s2. it takes a constant reference to
// s1 and s2. if their lengths are empty, then it returns true. if they are not
// empty, then it checks every member function from stats.h and compares their
// value.

} // namespace main_savitch_2C
  // ENDPROGRAM
