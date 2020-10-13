/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <Generafor.hpp>
#include <FString.hpp>
#include <Extend.hpp>

void
Generafor::HelpFunction(char* arg) {
	std::cout << arg <<  " [arguments]\n" 
	<< "arguments:\n" <<
	" --g: Generate application.\n" <<
	" --b: Build application.\n";
}

int main(int argc, char** argv) {
	Generafor main;
	
	if(argc < 2)
		main.HelpFunction(argv[0]);
	else {
		if(argv[1] == "--g") {
			std::cout << "Coming soon!\n";
		}
	}
	
	return 0;
}
