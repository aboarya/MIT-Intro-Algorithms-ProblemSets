#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@author: Sam Mohamed

Problem: Find a peak in a 1-d array.

Definition: A peak is any elemnt i such that i-1 < i > i+1

Proof: We look at the element n/2, then examine the elements on right and left sides.
If we find that n/2 is greater than both its left and right elements, then we are done.
If it is smaller than either of those two elements, then 

1) we choose n/2+1 to n and search for a peak in the left half similar to above.
2) we choose n/2-1 to 1 and search for a peak in the right half similar to above.

Complexity: O(log(n))

Usage:
    $ python3 -m doctest 1darray.py

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
