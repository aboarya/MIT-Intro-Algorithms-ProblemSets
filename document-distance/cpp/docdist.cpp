/**
*   @file    docdist.cpp
*   @author  Sam Mohamed
*   @version 0.1
*   @date    04/30/2017
*
*   @brief Document distance calculation
*
*   @section DESCRIPTION
*
*   Definition: Calculate the distance (similarity) between two documents as the angle between their word
*   count vectors.  Vectors are normalized against document length.  The smaller the angle, the more similar
*   the two documents are.
*   The "distance" between two vectors is the angle between them.
*   If x = (x1, x2, ..., xn) is the first vector (xi = freq of word i)
*   and y = (y1, y2, ..., yn) is the second vector,
*   then the angle between them is defined as:
*   d(x,y) = arccos(inner_product(x,y) / (norm(x)*norm(y)))
*   where:
*     inner_product(x,y) = x1*y1 + x2*y2 + ... xn*yn
*     norm(x) = sqrt(inner_product(x,x))
*
*	Complexity: O(nlog(n))
*
*   Usage:
*       $ make doc
*
*/
#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <math.h> 

std::string read_file(std::string filename)
{
	std::ifstream file(filename);
	std::stringstream buffer;

    buffer << file.rdbuf();
    std::string str = buffer.str();
    
    return str;
}

std::vector<std::string> get_words_from_filecontent(std::string filecontent)
{
	std::vector<std::string> words;
	std::regex rgx("\\w+");

	for( std::sregex_iterator it(filecontent.begin(), filecontent.end(), rgx), it_end; it != it_end; ++it )
        words.push_back((*it)[0]);

    return words;
}

std::map<std::string, int> count_frequency(std::vector<std::string> words) {
	std::map<std::string, int> m;

	for (std::string word : words)
	{
		if (m.find(word) == m.end())
		{
			m[word] = 1;
		} else{
			m[word] = m[word] + 1;
		}
	}

	std::cout << "word count " << m["MessageId"] << "\n";
	return m;
}

std::map<std::string, int> get_doc_vector(std::string filename)
{
	std::string content = read_file(filename);
	std::vector<std::string> words = get_words_from_filecontent(content);
	return count_frequency(words);
}

int inner_product(std::map<std::string, int> v1, std::map<std::string, int> v2)
{
	int sum = 0;
	for (auto const& key : v1) {
		if (v2.find(key.first) != v2.end())
		{
			sum += v1[key.first]*v2[key.first];
		}
	}
	return sum;
}

float vector_angle(std::map<std::string, int> v1, std::map<std::string, int> v2)
{
	float numerator = (float) inner_product(v1, v2);
	float denominator = sqrt(inner_product(v1, v1)*inner_product(v2, v2));
	return acos(numerator/denominator);
}


int main()
{   
	std::map<std::string, int> v1 = get_doc_vector("doc1.txt");
	std::map<std::string, int> v2 = get_doc_vector("doc2.txt");

	std::cout << "similarity = " << vector_angle(v1, v2) << "\n";


}