#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@author: Sam Mohamed

Problem: Sort an array of integers in ascending order.

Definition: Given an array of integers, sort the array
in ascending order using a divide and conquer approach.

The array is split in left and right recursively and
merged into a final ouput array by comparing the elements
in the left and right array and appending them to the output
based on increasing value.

Complexity: O(n log(n))

Usage:
    $ python3 -m doctest merge_sort.py
"""

def merge(left, right):
    result = []
    i , j = 0 , 0
    while i < len (left) and j < len (right):
        if left[i] <= right [j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1

    result += left[i:]
    result += right[j:]
    return result

def mergesort(lst):
    """
    >>> mergesort([])
    []
    >>> mergesort([3,2,1,5,6,7,9,4,8])
    [1, 2, 3, 4, 5, 6, 7, 8, 9]
    >>> mergesort([1,2,3,5,4,3,2,4,7,8,9])
    [1, 2, 2, 3, 3, 4, 4, 5, 7, 8, 9]
    >>> mergesort([1,1,1,1,1,1])
    [1, 1, 1, 1, 1, 1]
    >>> mergesort([9,8,7,6,5,4,3,2,1])
    [1, 2, 3, 4, 5, 6, 7, 8, 9]
    """
    if len(lst) <= 1:
        return lst

    middle = int(len(lst) / 2)
    left = mergesort(lst[:middle])
    right = mergesort(lst[middle:])
    
    return merge(left, right)
