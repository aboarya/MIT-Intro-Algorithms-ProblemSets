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
def find_a_peak(array):
    """
    >>> find_a_peak([]) is None
    True
    >>> find_a_peak([1,2,3,5,4,6,7,8,9])
    5
    >>> find_a_peak([1,2,3,5,4,3,7,8,9])
    5
    >>> find_a_peak([1,2,3,4,5,6,7,8,9])
    9
    >>> find_a_peak([9,2,3,4,5,6,7,8])
    8
    >>> find_a_peak([1,2,3,4,5,4,3,2])
    5
    >>> find_a_peak([1,2,3,4,5,5,4,3,2])
    5
    >>> find_a_peak([1,2,3,5,5,4,6,7,8,9])
    5
    >>> find_a_peak([1,2,1,1,1,1,1])
    2
    """
    if len(array) == 0:
        return None

    if len(array) == 2:
        return array[1]

    half = len(array) // 2

    if array[half-1] < array[half] and array[half] > array[half+1]:
        return array[half]

    if array[half-1] >= array[half]:
        return find_a_peak(array[0:half])

    if array[half+1] >= array[half]:
        return find_a_peak(array[half:len(array)])
