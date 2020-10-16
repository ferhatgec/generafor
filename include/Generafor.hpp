/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef GENERAFOR_HPP
#define GENERAFOR_HPP

#include <iostream>

class Generafor {
private:
	std::string app_name;
	std::string app_website;
	std::string app_icon;
	std::string app_subtitle;
	
	std::string comment_data;
	std::string app_data;
	std::string build_data;
	
	std::string window_x;
	std::string window_y;
public:
	void HelpFunction(char* arg);
	void GeneratorInfo();
	void Generator();
	
	void Build();
};

#endif /* GENERAFOR_HPP */
