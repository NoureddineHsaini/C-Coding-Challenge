/**
* @file < README.md >
* @author < Noureddine HSAINI>
* @date 27/01/2019

* @Description: In this project I worked Create a C++ program that can parse and evaluate arithmetic expressions. For example, on input 3+(5+(4*3))-12, 
                the program return 8. This program can also detect an invalid input and report an appropriate error. For example, on input 3/0  the program 
			    return error "devide by 0". 
				- The project consists of three files : - main.cpp         : the main program.
				                                        - My_Functions.cpp : in this file I implemented all the project functions.
														- My_Functions.h   : in this file I declared all the project functions  prototype.
														
                - These are the functions I programmed:

                                                      - main()      : The main entry point for your program
                                                      - get_token() : the role of this function is to check the type of symbol
                                                      - expr(bool)  : the role of this function is to calculate add and subtract
                                                      - prim(bool)  : the role of this function is to calculate unary minus and Pi 
                                                      - term(bool)  : the role of this function is to calculate  multiply and divide
                                                      - error(const string& ) : the role of this function is to manage the number and type of errors
 **/
