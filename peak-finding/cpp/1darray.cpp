/**
*   @file    1darray.cpp
*   @author  Sam Mohamed
*   @version 0.1
*   @date    04/20/2017
*
*   @brief Find a peak in a 1-d array.
*
*   @section DESCRIPTION
*
*   Definition: A peak is any elemnt i such that i-1 < i > i+1
*
*   Proof: We look at the element n/2, then examine the elements on right and left sides.
*   If we find that n/2 is greater than both its left and right elements, then we are done.
*   If it is smaller than either of those two elements, then 
*
*   1) we choose n/2+1 to n and search for a peak in the left half similar to above.
*   2) we choose n/2-1 to 1 and search for a peak in the right half similar to above.
*
*   Complexity: O(log(n))
*
*   Usage:
*       $ make oned
*
*/
#include <iostream>
#include <vector>
#include <stdexcept>

int find_a_peak(std::vector<int> array)
{
    int len = array.size();

    if (len == 0) { throw std::logic_error ( "invalid input" ); }
    if (len == 2) { return array[1];}

    int half = len / 2;
    if ((array[half-1] < array[half]) && (array[half] > array[half+1])) {
        return array[half];
    }
    
    if (array[half-1] >= array[half]) {
        std::vector<int> slice(array.begin(), array.begin()+half);
        return find_a_peak(slice);
    }

    if (array[half+1] >= array[half]) {
        std::vector<int> slice(array.begin()+half, array.end());
        return find_a_peak(slice);
    }

}
int main()
{
    // std::vector<int> array = {1,2,3,5,4,6,7,8,9};1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    std::vector<int> array = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << "the peak is " << find_a_peak(array) << "\n";

}