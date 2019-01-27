/******************************************************************************
 * @author <Noureddine HSAINI>
 * @date <26/01/2019 >
 * @file < main.cpp>
 * @brief < the main program>
 *****************************************************************************/

#include "My_Functions.h"
using namespace std;



int main(int argc, char* argv[]) {

	istream* input;// pointer to input stream
	switch (argc) {
	case 1:
		input = &cin;
		break;
	case 2:
		input = new istringstream(argv[1]);
		break;
	default:
		error("too many arguments");
		return 1;
	}

	table["pi"] = 3.14;
	table["e"] = 2.71;

	while (cin) {
		get_token();
		if (curr_tok == END)
			break;
		if (curr_tok == PRINT)
			continue;
		cout << expr(false) << "\n";
	}

	if (input != &cin) delete input;
	return num_of_errors;
}