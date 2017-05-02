# MIT Intro to Algorithms Problem Sets

## Overview

* [Introduction](#introduction)
* [Peak Finding](#peak-finding)
* [Document Distance](#document-distance)
* [Merge Sort](#merge-sort)

## Introduction

This repository holds implementations of the algorithms described in the [MIT OpenCourseWare](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/index.htm) in both `python` and `c++`

## Peak Finding

A peak in a 1-d array is any integer at index __i__, such that __i-1 < i > i+1__.  We are only concerned with finding __any__ peak in the 1-d array vs. all peaks.

[Solution](./peak-finding)

A peak in a 2-d array is a hill in the matrix, such that the elemnt (j,j) is greather than all elements in north, south, east and west of it.

[Solution](./peak-finding)

## Document Distance

The distance between two documents is calculated as the angle between the word count vector of each of the
documents.  The `python` implementation was provided as lecture supporting material and the `c++` is my port of it.

The algorithm can be described as follows:

1. create a word count vector of each of the documents
2. calculate the inner product of the two vectors
3. normalize to the document length
4. calculate the distance as the arccosine of the normalized inner products

More formally:

`d(x,y) = arccos(inner_product(x,y) / (norm(x)*norm(y)))`
where:
```
inner_product(x,y) = x1*y1 + x2*y2 + ... xn*yn
norm(x) = sqrt(inner_product(x,x))
```

[Python Solution](./document-distance/python)
[C++ Solution](./document-distance/cpp)

## Merge Sort

A `divide and conquer` sorting technique that sequences data by continuously merging items in the list. Every single item in the original unordered list is merged with another, creating groups of two. Every two-item group is merged, creating groups of four and so on until there is one ordered list.

[Python Solution](./merge-sort/python)
[C++ Solution](./merge-sort/cpp)

