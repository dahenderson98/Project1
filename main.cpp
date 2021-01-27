/*
main.cpp
Dallin Henderson
Lab 1 - Scanner/Tokenizer
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include "Lexer.h"

using namespace std;

int main(int argc, char* argv[]) {
	string fileName = argv[1] /*"abcdefg"*/;
	Lexer* myLexer = new Lexer(fileName);

	vector<Token*> tokens = myLexer->start();		//Returns vector of tokens to be output
		
	for (int i = 0; i < tokens.size(); i++) {		//Prints all tokens
		cout << tokens.at(i)->toString() << endl;
	}
	cout << "Total Tokens = " << tokens.size() << endl;

	delete myLexer;								//Deallocate memory - revisit this
	

	//system("pause");

	return 0;
}

