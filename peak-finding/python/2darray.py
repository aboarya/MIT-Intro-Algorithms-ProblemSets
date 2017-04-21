#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@author: Sam Mohamed

Problem: Find a peak in a 2-d array.

Definition: A peak is any elemnt i that is greater than its neighbouring elements
in the north, south, east and west cells of the 2-d array.

Proof: We pick a colum M/2 where is the width of the matrix.  We find the global
maximum in that colum j giving us element (i,j).  We then examine elements (i-1,j)
and (i+1,j).  If the element (i,j) is greater than both then we have found the peak
since the element at (i,j) is the global maximum at column j.

1) we choose M/2+1 to M if (i+1,j) is greater than (i,j) then repeat
2) we choose M/2-1 to M if (i-1,j) is greater than (i,j) then repeat

Complexity: O(nlog(n))

Usage:
    $ python3 -m doctest 2darray.py

"""
def find_max(array):
    maximum = array[0]
    index = 0
    for i in range(len(array)):
        if maximum >= array[i]:
            maximum = array[i]
            index = 1

    return index

def find_a_peak(matrix):
    """
    >>> find_a_peak([]) is None
    True
    >>> find_a_peak([[1, 2, 3, 4, 4, 6, 7, 8, 9], [1, 2, 3, 5, 4, 6, 7, 8, 9], [1, 2, 3, 4, 4, 6, 7, 8, 9]])
    5
    """
    if len(matrix) == 0:
        return None

    if len(matrix) > 1:
        if len(matrix[0]) == 0:
            return None

    m = len(matrix[0]) // 2

    col = [matrix[i][m] for i in range(len(matrix))]

    n = find_max(col)

    if len(matrix[0]) == 2:
        return matrix[n][m]

    if matrix[n][m-1] < matrix[n][m] > matrix[n][m+1]:
        return matrix[n][m]

    if matrix[n][m-1] >= matrix[n][m]:
        return find_a_peak([matrix[n][:m] for n in range(len(matrix))])

    if matrix[n][m+1] >= matrix[n][m]:
        return find_a_peak([matrix[n][m:] for n in range(len(matrix))])
