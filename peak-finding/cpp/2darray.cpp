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

class Matrix
{
private:
    size_t rows, columns;
    std::vector<int> matrix;
public:
    Matrix(size_t numrows, size_t numcols) :
            rows(numrows), columns(numcols), matrix(rows * columns)
    {
    }

    int & operator()(size_t row, size_t column)
    {
        return matrix[row * columns + column]; // note 2D coordinates are flattened to 1D
    }

    int operator()(size_t row, size_t column) const
    {
        return matrix[row * columns + column];
    }

};

int find_max(std::vector<int> col)
{
	int max = col[0];
	int index = 0;
	for (int i=0; i < col.size(); i++)
	{
		if (max <= col[i])
		{
			max = col[i];
			index = i;
		}
	}
	return index;
}

int find_a_peak(Matrix matrix, int n, int m)
{

	if (m <= 2) {
		return matrix(0, 0);
	}

	
	int mid = (m/2);
	int start, end;
	std::vector<int> col(n);
	for (int i=0; i < n; i++) {
		col[i] = matrix(i, mid);
	}

	int max = find_max(col);

	if (matrix(max, mid-1) < matrix(max, mid) > matrix(max, mid+1)) { return matrix(max, mid);}

	if (matrix(max, mid-1) >= matrix(max, mid))
	{
		// std::cout << " test " << matrix(max, mid-1) << " end " << mid << "\n";
		start = 0; end = mid;
	}

	if (matrix(max, mid+1) >= matrix(max, mid))
	{
		// std::cout << " test1 " << matrix(max, mid+1) << " start " << mid << " end " << m << "\n";
		start = mid; end = m;
	}

	Matrix submatrix(3, mid);
    for (int i=0; i < 3; i++){
    	for (int j=start; j < end; j++) {
    		submatrix(i, j) = matrix(i, j);
    	}
    }

    return find_a_peak(submatrix, n, mid);

}

int main()
{
	int n = 3, m = 9;
	int tmp [27] = {1, 2, 2, 4, 2, 6, 7, 8, 9,
		            1, 2, 3, 5, 3, 1, 7, 8, 9,
		            1, 2, 1, 4, 1, 6, 7, 8, 9};

    Matrix matrix(3,9);
    for (int i=0; i < 3; i++){
    	for (int j=0; j<9; j++) {
    		matrix(i,j) = tmp[i*9+j];
    	}
    }
    
    std::cout << find_a_peak(matrix, n, m) << "\n";
}