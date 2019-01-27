/******************************************************************************
 * @author <Noureddine HSAINI>
 * @date <26/01/2019 >
 * @file < My_Functions.cpp>
 * @brief < in this file I declared all the project functions>
 *****************************************************************************/


#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H
 /*--------------------------- Includes ---------------------------------------*/
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>

/*--------------------------- Global variables -------------------------------*/
extern std::map<std::string, double> table;
enum Token_value {
	NAME,
	NUMBER,
	END,
	PLUS = '+',
	MINUS = '-',
	MUL = '*',
	DIV = '/',
	PRINT = ';',
	ASSIGN = '=',
	LP = '(',
	RP = ')'
};

extern Token_value curr_tok;
extern int num_of_errors;
extern double number_value;
extern std::string string_value;

/*------------------------------functions prototype ---------------------*/

/**
 * @brief the role of this function is to check the type of symbol

 */
Token_value get_token();
/**
 * @brief the role of this function is to do add and subtract

 */
double expr(bool);
/**
 * @brief the role of this function is to calculate unary minus and Pi 
 */
double prim(bool);
/**
 * @brief the role of this function is to calculate  multiply and divide

 */

double term(bool);
/**
 * @brief the role of this function is to manage the number and type of errors

 */
double error(const std::string& s);



#endif /* MY_FUNCTIONS_H */