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
		if (max >= col[i])
		{
			max = col[i];
			index = i;
		}
	}
	return index;
}

int find_a_peak(Matrix matrix)
{
	// int len = matrix[0].size();
	// int m = len / 2;
	// std::cout << "m is " << m;
	// std::vector<int> col(3, 0);
	// for (int i=0; i < m; i++)
	// 	col[i] = matrix[i][m];
	
	// int n = find_max(col);
	// std::cout << " n is " << n;

	// if (matrix[0].size() == 2) {return matrix[n][m];}

	// if (matrix[n][m-1] < matrix[n][m] > matrix[n][m+1]){return matrix[n][m];}
	
	// if (matrix[n][m-1] >= matrix[n][m])
	// {

 //   		std::vector<std::vector<int> > submatrix; 
 //    	for (int i=0; i < matrix.size(); i++) {
 //        	submatrix.push_back(std::vector<int>(matrix[i].begin(), matrix[i].begin() + m));
 //    	}
 //    	return find_a_peak(submatrix);
	// }

	// if (matrix[n][m+1] >= matrix[n][m])
	// {
 //   		std::vector<std::vector<int> > submatrix; 
 //    	for (int i=0; i < matrix.size(); i++) {
 //        	submatrix.push_back(std::vector<int>(matrix[i].begin() + m, matrix[i].end()));
 //    	}
 //    	return find_a_peak(submatrix);
	// }

	return 0;
}

int main()
{
    Matrix matrix(3,9);
    std::cout << "the peak is " << find_a_peak(matrix) << "\n";
}