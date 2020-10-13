/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdio>
#include <cstdarg>
#include "../include/Extend.hpp"
#include "../include/FString.hpp"

int FExtend::Print(const FString& _str, ...) {
    /* Create new char* with _str.len */
    char* data = new char[_str.len()];
    va_list arg;
  	int done;

    /* Copy data */  
    for(unsigned f = 0; f < _str.len(); f++)
        data[f] = _str[f];

  	va_start (arg, NULL);
    done = vfprintf (stdout, data, arg);
  	
    va_end (arg);

    return done;
}