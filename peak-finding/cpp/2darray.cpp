/**
*   @file    2darray.cpp
*   @author  Sam Mohamed
*   @version 0.1
*   @date    04/21/2017
*
*   @brief Find a peak in a 2-d array.
*
*   @section DESCRIPTION
*
*   Definition: We pick a colum M/2 where is the width of the matrix.  We find the global
*	maximum in that colum j giving us element (i,j).  We then examine elements (i-1,j)
*	and (i+1,j).  If the element (i,j) is greater than both then we have found the peak
*	since the element at (i,j) is the global maximum at column j.
*
*	1) we choose M/2+1 to M if (i+1,j) is greater than (i,j) then repeat
*	2) we choose 0 to M/2-1 if (i-1,j) is greater than (i,j) then repeat
*
*	Complexity: O(nlog(n))
*
*   Usage:
*       $ make twod
*
*/
#include <iostream>
#include <vector>
#include <stdexcept>