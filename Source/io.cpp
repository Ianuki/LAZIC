#include <iostream>

#include "../Headers/io.h"
#include "../Headers/defines.h"

void io::write(const char * output_line) {
    std::cout << output_line << std::endl;    
}

void io::read(char * input_line) {
    std::cin.getline(input_line, MAX_LINE_LENGTH);    
}

void io::clear() {
    #ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}
