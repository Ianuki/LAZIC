#include <iostream>
#include <cstdlib> 
#include <cstring>

#include "Headers/LAZIC.h"

// -- TODO: Transfer the commands to another file

typedef void (*command_interface)(int argc, char ** argv);

struct command {
	char name[COMMAND_MAX_LENGTH];
	char aka[COMMAND_MAX_LENGTH];
	command_interface function;
};

void clear_command(int argc, char ** argv) {
	#ifdef _WIN32
	system("cls");
	#else
	system("clear")
	#endif
}

void exit_command(int argc, char ** argv) {
	exit(0);
}

void fetch_command(int argc, char ** argv) {
	std::cout << " * LAZIC VERSION: " << LAZIC_VERSION << std::endl;
	std::cout << " * LINE LENGTH: " << MAX_LINE_LENGTH << std::endl;
	std::cout << " * MAX LINES: " << MAX_LINES << std::endl;
	std::cout << " * AVAILABLE LAZIC BYTES: " << MAX_LINE_LENGTH * MAX_LINES * sizeof(char) << std::endl;
	std::cout << " * COLOR: " << COLOR << std::endl;
	std::cout << " * AKA: " << AKA << std::endl;
	std::cout << std::endl;
}

command command_registry[] = {
	{"exit", "quit", exit_command},
	{"clear", "cls", clear_command},
	{"fetch", "fch", fetch_command},
};

// -- TODO: Move this to the tokenizer file 

int tokenize(char * input, char * argv[], int max_args) {
	int argc = 0;
	char* p = input;

	while (*p != '\0' && argc < max_args) {
		// skip leading spaces
		while (*p == ' ') p++;
		if (*p == '\0') break;

		argv[argc++] = p;

		// find next space or end
		while (*p != ' ' && *p != '\0') p++;
		if (*p == ' ') {
			*p = '\0'; // null-terminate token
			p++;
		}
	}
	return argc;
}


const int TOTAL_COMMANDS = sizeof(command_registry) / sizeof(command);

void dispatch_command(char input_line[MAX_LINE_LENGTH]) {
	char* argv[10];
	int argc = tokenize(input_line, argv, 10);

	if (argc == 0) return;

	for (int i = 0; i < TOTAL_COMMANDS; ++i) {
		if (
			strcmp(argv[0], command_registry[i].name) == 0
			||
			strcmp(argv[0], command_registry[i].aka) == 0
		) {
			command_registry[i].function(argc, argv);
			return;
		}
	}

	std::cout << "Unknown command: " << argv[0] << std::endl;
}

void get_and_validate_input(char * input_storage) {
	std::cin.getline(input_storage, MAX_LINE_LENGTH);
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int main(int argc, char ** argv) {
	std::cout << "TERMINAL INFORMATION: " << MAX_LINE_LENGTH << std::endl;
	std::cout << "\t* LAZIC VERSION: " << LAZIC_VERSION << std::endl;
	std::cout << "\t* LINE LENGTH: " << MAX_LINE_LENGTH << std::endl;
	std::cout << "\t* MAX LINES: " << MAX_LINES << std::endl;
	std::cout << "\t* AVAILABLE LAZIC BYTES: " << MAX_LINE_LENGTH * MAX_LINES * sizeof(char) << std::endl;
	std::cout << "\t* COLOR: " << COLOR << std::endl;
	std::cout << "\t* AKA: " << AKA << std::endl;
	std::cout << std::endl;
	
	bool running = true;
	char input_line[MAX_LINE_LENGTH];
	while (running) {
		std::cout << "$ ";

		get_and_validate_input(input_line);
		dispatch_command(input_line);
	}

	return 0;
}
