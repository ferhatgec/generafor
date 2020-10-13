/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef FSTRING_HPP
#define FSTRING_HPP

#include <iostream>   

/*
        #define UNSIGNED unsigned
        #define CONST const
        #define CHAR char
        #define CHARP char*
*/

class FString { 
    char* data; 
    unsigned length;
public: 
    FString(); 
    ~FString();

    FString(char ch);
  
    FString(const char* ch);

    FString(const FString& _str);
  
    friend std::ostream& operator<< (std::ostream& ostr, 
        const FString& _str);
        
    char operator[] (unsigned _ch) const;
    char& operator[] (unsigned _ch);

    FString& append(const FString& _str); 
    FString& append(const char* _ch);
    FString& append(char _ch);

    FString& append(const FString& _str_1,
        const FString& _str_2);


    FString& append(const FString& _str_1,
        const char* _ch);

    FString& equal(const FString& _str);
    FString& equal(const char* _ch);
    FString& equal(char _ch);

    unsigned len() const; 

    friend bool operator== (const FString& _str_1, 
        const FString& _str_2);

    friend bool operator== (const FString& _str_1, char _ch);

    friend bool operator!= (const FString& _str_1, const FString& _str_2);
    friend bool operator!= (const FString& _str, char _ch);

    void pop_back();

    int compare(FString& _str);
    int compare(const char* _ch);
    int compare(char _ch);

    int ch_conv_int(char _ch);

    int conv_int();

    bool empty();

    int find(const FString& _str);
    int find(const char* _ch);
}; 


#endif /* FSTRING_HPP */