/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef GENERAFOR_HPP
#define GENERAFOR_HPP

#include <iostream>
#include "FString.hpp"

class Generafor {
private:
	FString app_name();
	FString app_website();
	FString app_icon();
public:
	void HelpFunction(char* arg);
};

#endif /* GENERAFOR_HPP */
