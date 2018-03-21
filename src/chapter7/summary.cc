#include <iostream>
#include <utility>
#include <array>
#include <assert.h>
#include <limits.h>

using std::cout;
using std::cin;
using std::endl;

double max(const double a, const double b)
{
   if( a > b )
      return a;
   else
      return b;
}

int& getLargestElement(int *array, int length)
{
   assert(array && "Passed array reference is nullptr");

   int largestIdx = 0, largest = INT_MIN;
   for (int i = 0; i < length; ++i)
   {
      if(array[i] > largest)
      {
         largestIdx = i;
         largest = array[i];
      }
   }

   return array[largestIdx];
}

void swap(int &a, int &b)
{
   std::swap(a,b);
}

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearchIterative(int *array, int target, int min, int max)
{
   while ( min <= max )
   {
      int midpoint = min + ((max - min) / 2); /* Such midpoint calculation prevent
                                               * overflow when min or/and max are
                                               * close to INT_MAX. In contrast to
                                               * normal average counting. */
      if (array[midpoint] > target)
      {
         max = midpoint - 1; // we can skip midpoint toward correct direction
                             // as it has been verified
      }
      else if (array[midpoint] < target)
      {
         min = midpoint + 1; // we can skip midpoint toward correct direction
         // as it has been verified
      }
      else
         return midpoint;
   }
   return -1;
}
int binarySearchRecursive(int *array, int target, int min, int max)
{
   int midpoint = min + ((max - min) / 2);
   if(min > max) // stop condition reversed: We stop if true instead continue while false
      return -1;
   else if (array[midpoint] > target)
      return binarySearchRecursive(array, target, min, midpoint - 1);
   else if (array[midpoint] < target)
      return binarySearchRecursive(array, target, midpoint + 1, max);
   else
      return midpoint;
}

int main_summary()
{

   std::cout << std::endl << "-------------------------------" << std::endl
         << "Chapter 7 summary" << endl;

   {
      cout << "Tab printing" << endl;
      int tab[]
      { 3, 5, 8, 12, 13, 24, 8 };
      int &tmp = getLargestElement(tab, sizeof(tab) / sizeof(int));

      for (unsigned int i = 0; i < sizeof(tab) / sizeof(int); ++i)
         cout << tab[i] << ", ";
      cout << endl;

      cout << tmp << endl;
      tmp = 333;
      cout << tmp << endl;

      for (unsigned int i = 0; i < sizeof(tab) / sizeof(int); ++i)
         cout << tab[i] << ", ";
      cout << endl;
      cout << "---------------------" << endl;
   }

   {
      cout << "Iterative binary search" << endl;
      int array[] =
      { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

      // We're going to test a bunch of values to see if they produce the expected results
      const int numTestValues = 10;
      // Here are the test values
      int testValues[numTestValues] =
      { 0, 3, 12, 13, 22, 26, 43, 44, 48, 49 };
      // And here are the expected results for each value
      int expectedValues[numTestValues] =
      { -1, 0, 3, -1, -1, 8, -1, 13, 14, -1 };

      // Loop through all of the test values
      for (int count = 0; count < numTestValues; ++count)
      {
         // See if our test value is in the array
         int index = binarySearchIterative(array, testValues[count], 0, 14);
         // If it matches our expected value, then great!
         if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
         else
            // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count]
                  << " failed. (return index: "<< index << ") There's something wrong with your code!\n";
      }
      cout << "---------------------" << endl;
   }

   {
      cout << "Recursive binary search" << endl;
      int array[] =
      { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

      // We're going to test a bunch of values to see if they produce the expected results
      const int numTestValues = 10;
      // Here are the test values
      int testValues[numTestValues] =
      { 0, 3, 12, 13, 22, 26, 43, 44, 48, 49 };
      // And here are the expected results for each value
      int expectedValues[numTestValues] =
      { -1, 0, 3, -1, -1, 8, -1, 13, 14, -1 };

      // Loop through all of the test values
      for (int count = 0; count < numTestValues; ++count)
      {
         // See if our test value is in the array
         int index = binarySearchRecursive(array, testValues[count], 0, 14);
         // If it matches our expected value, then great!
         if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
         else
            // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count]
                  << " failed. (return index: "<< index << ") There's something wrong with your code!\n";
      }
      cout << "---------------------" << endl;
   }

   std::cout << "-------------------------------";
   return 0;
}
