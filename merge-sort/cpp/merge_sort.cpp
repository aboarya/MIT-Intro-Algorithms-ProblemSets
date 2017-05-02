/**
*   @file    mergesort.cpp
*   @author  Sam Mohamed
*   @version 0.1
*   @date    05/01/2017
*
*   @brief Sort an array of integers in ascending order.
*
*   @section DESCRIPTION
*
*   Definition:  Given an array of integers, sort the array
*   in ascending order using a divide and conquer approach.
*   The array is split in left and right recursively and
*   merged into a final ouput array by comparing the elements
*   in the left and right array and appending them to the output
*   based on increasing value.
*
*   Complexity: O(nlog(n))
*
*   Usage:
*       $ make mergesort
*
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

template<typename I>
void doMerge(I begin, I midPoint, I end)
{
    typedef std::vector<typename std::iterator_traits<I>::value_type> TmpVec;

    TmpVec tmp(std::make_move_iterator(begin), std::make_move_iterator(end));

    typename TmpVec::iterator   beginAlt   = std::begin(tmp);
    typename TmpVec::iterator   endAlt     = std::end(tmp);
    typename TmpVec::iterator   midAlt     = std::next(beginAlt, std::distance(begin, midPoint));


    typename TmpVec::iterator   l   = beginAlt;
    typename TmpVec::iterator   r   = midAlt;
    I                  i   = begin;

    while(l < midAlt && r < endAlt)
    {
        *i = std::move((*l < *r) ? *l++ : *r++);
        ++i;
    }
    while(l < midAlt)
    {   *i  = std::move(*l++);
        ++i;
    }
    while(r < endAlt)
    {   *i  = std::move(*r++);
        ++i;
    }
}
template<typename I>
void mergeSort(I begin, I end)
{
    std::size_t length  = std::distance(begin, end);
    if (length <= 1)
    {   return;
    }

    std::size_t mid      = length/2;
    I           midPoint = std::next(begin, mid);

    mergeSort(begin, midPoint);
    mergeSort(midPoint, end);

    doMerge(begin, midPoint, end);
}


int main()
{
    std::vector<int>    data  {{ 5,12,45,2,67,8}};
    mergeSort(std::begin(data), std::end(data));

    std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n";
}