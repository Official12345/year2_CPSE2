#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>

int main( int argc, char *argv[] ){

/*---------------------Opdracht 1---------------------*/
	std::ifstream file("text.txt");
	std::vector<char> vector1;
	char c;
	while (file.get(c)) {
		vector1.push_back(c);
	}
	/*---------------------Opdracht 2---------------------*/
	std::cout << "number of chars: " << vector1.size() << '\n';
	/*---------------------Opdracht 3---------------------*/
	std::cout << "number of lines: " << count(vector1.begin(), vector1.end(), '\n') << '\n';
	/*---------------------Opdracht 4---------------------*/
	std::cout << "number of alphabetical chars: " << count_if(vector1.begin(), vector1.end(), [](char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }) << "\n";
	/*---------------------Opdracht 5---------------------*/
	for_each(vector1.begin(), vector1.end(), [](char &c) { if (c >= 'A' && c <= 'Z') c -= 32; });

	std::array<int, 26> count_array;
	count_array.fill(0);

	std::unordered_map<char, int> temp_map;
	std::unordered_map<char, int>::iterator it;

	/*---------------------Opdracht 6---------------------*/

	for (unsigned int i = 0; i < vector1.size(); i++) {
		if (vector1[i] >= 'a' && vector1[i] <= 'z') {
			int difference;
			difference = vector1[i] - 'a';
			count_array[difference] += 1;
		}
	}

	for (unsigned int i = 0; i < count_array.size(); i++) {
		std::cout << char('a'+i) << ": " <<  count_array[i] << '\n';
	}

	/*---------------------Opdracht 7---------------------*/

/*
	for (unsigned int i = 0; i < vector1.size(); i++) {
		if (temp_map.count(vector1[i])) {

		}

		if (vector1[i] >= 'a' && vector1[i] <= 'z') {
			temp_map.insert(std::make_pair('a' + i, 0));
		}
	}




	for (it = temp_map.begin(); it != temp_map.end(); it++) {
		std::cout << it->first << '\n';
	}
*/
	return 0;
}

