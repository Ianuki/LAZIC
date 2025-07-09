/*

	This program helps me debug 

*/

#include <iostream>
#include <cstdlib> 
#include <cstring>

#include "../Headers/LAZIC.h"

void get_and_validate_input(char * input_storage) {
	std::cin.getline(input_storage, MAX_LINE_LENGTH);
}

int main(int argc, char ** argv) {
	std::cout << "LAZIC INFORMATION: " << MAX_LINE_LENGTH << std::endl;
	std::cout << "\t* LAZIC VERSION: " << LAZIC_VERSION << std::endl;
	std::cout << "\t* LINE LENGTH: " << MAX_LINE_LENGTH << std::endl;
	std::cout << "\t* MAX LINES: " << MAX_LINES << std::endl;
	std::cout << "\t* AVAILABLE LAZIC BYTES: " << MAX_LINE_LENGTH * MAX_LINES * sizeof(char) << std::endl;

	char input_file_name[MAX_LINE_LENGTH];
	std::cout << "\nEnter input file: ";
	get_and_validate_input(input_file_name);

	return 0;
}
