/******************************************************************************
 * @author <Noureddine HSAINI>
 * @date <26/01/2019 >
 * @file < My_Functions.cpp>
 * @brief <in this file I implemented all the project functions>
 *****************************************************************************/

#include "My_Functions.h"
using namespace std;

/*--------------------------- Global variables -------------------------------*/
map<string, double> table;
Token_value curr_tok = PRINT;
int num_of_errors;


/*--------------------------- implementation of functions -------------------------------*/

double error(const string& s) {
	num_of_errors++;
	cerr << "ERROR : " << s << endl;
	return 1;
}

double number_value;
string string_value;

Token_value get_token() {

	char ch;
	do { // skip whitespace except '\n'
		if (!cin.get(ch))
			return curr_tok = END;
	} while (ch != '\n' && isspace(ch));

	switch (ch) {
	case ';':
	case '\n':
		return curr_tok = PRINT;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok = Token_value(ch);
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '.':
		cin.putback(ch);
		cin >> number_value;
		return curr_tok = NUMBER;
	default: // name
		if (isalpha(ch)) { // is letter
			string_value = ch;
			while (cin.get(ch) && isalnum(ch))
				string_value.push_back(ch);
			cin.putback(ch);
			return curr_tok = NAME;
		}
		error("bad token");
		return curr_tok = PRINT;

	}
}


double prim(bool get) {
	if (get)
		get_token();
	switch (curr_tok) {
	case NUMBER: {
		double v = number_value;
		get_token();
		return v;
	}
	case NAME: {
		double& v = table[string_value];
		if (get_token() == ASSIGN)
			v = expr(true);
		return v;
	}
	case MINUS:
		return -prim(true);// unary minus
	case LP: {
		double v = expr(true);
		if (curr_tok != RP)
			return error(") expected");
		get_token(); // eat ')'
		return v;
	}
	default:
		return error("primary expected");

	}
}
// multiply and divide
double term(bool get) {

	double left = prim(get);
	for (;;)// forever
		switch (curr_tok) {
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true)) {
				left /= d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
		}
}

// add and subtract
double expr(bool get) {

	double left = term(get);
	for (;;)// forever
		switch (curr_tok) {
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left -= term(true);
			break;
		default:
			
			return left;
			
			
		}

}