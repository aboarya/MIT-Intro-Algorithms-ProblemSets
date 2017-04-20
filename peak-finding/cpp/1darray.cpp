#include <iostream>
#include <vector>
#include <stdexcept>

int find_a_peak(std::vector<int> array)
{
	int len = array.size();

	if (len == 0) { throw std::logic_error ( "invalid input" ); }
	if (len == 2) { return array[1];}

	int half = len / 2;
	if ((array[half-1] <= array[half]) && (array[half] >= array[half+1])) {
		return array[half];
	}
	
	if (array[half-1] > array[half]) {
		std::vector<int> slice(array.begin(), array.begin()+half);
		return find_a_peak(slice);
	}

	if (array[half+1] > array[half]) {
		std::vector<int> slice(array.begin()+half, array.end());
		return find_a_peak(slice);
	}

}
int main()
{
	std::vector<int> array = {1,2,3,5,4,6,7,8,9};
	std::cout << find_a_peak(array) << "\n";

}