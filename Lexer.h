/*
Lexer.h
Project 1: Scanner/Tokenizer
Dallin Henderson
*/

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include "Tokenizer.h"

using namespace std;

class Lexer {
public:
	Lexer(string fileName) {
		fileContents.open(fileName);
		if (!fileContents.is_open()) {
			cout << "Could not open file" << endl;
		}
	}
	ifstream fileContents;
	Tokenizer tokenizer;
	int currentLine = 1;
	vector<Token*> tokens;

	vector<Token*> start() {
		if (!fileContents.is_open()) {
			return tokens;
		}
		char c;
		int linesAdvanced = 0;
		do {
			fileContents.get(c);
			if (fileContents.eof()) {	// EOF
				c = EOF;
				tokenizer.getNextToken("EofF", currentLine);
				break;
			}
			else if (isspace(c)) {
				if (c == '\n') {
					currentLine++;
				}
				else {
					//Do nothing, skip character
				}
			}
			else {
				bool inString = true;
				string str = "";

				switch (c) {
				case ',':			//COMMA
					tokenizer.getNextToken("COMMA", currentLine);
					break;
				case '.':			//PERIOD
					tokenizer.getNextToken("PERIOD", currentLine);
					break;
				case '?':			//Q_MARK
					tokenizer.getNextToken("Q_MARK", currentLine);
					break;
				case '(':			//LEFT_PAREN
					tokenizer.getNextToken("LEFT_PAREN", currentLine);
					break;
				case ')':			//RIGHT_PAREN
					tokenizer.getNextToken("RIGHT_PAREN", currentLine);
					break;
				case ':':			//COLON or COLON_DASH
					if (fileContents.peek() == '-') {
						fileContents.get(c);
						tokenizer.getNextToken("COLON_DASH", currentLine);
					}
					else {
						tokenizer.getNextToken("COLON", currentLine);
					}
					break;
				case '*':			//MULTIPLY
					tokenizer.getNextToken("MULTIPLY", currentLine);
					break;
				case '+':			//ADD
					tokenizer.getNextToken("ADD", currentLine);
					break;
				case 'S':			//SCHEMES
					if (fileContents.peek() == 'c') {
						fileContents.get(c);
						if (fileContents.peek() == 'h') {
							fileContents.get(c);
							if (fileContents.peek() == 'e') {
								fileContents.get(c);
								if (fileContents.peek() == 'm') {
									fileContents.get(c);
									if (fileContents.peek() == 'e') {
										fileContents.get(c);
										if (fileContents.peek() == 's') {
											fileContents.get(c);
											tokenizer.getNextToken("SCHEMES", currentLine);
										}
										else if (isspace(fileContents.peek())) {
											fileContents.get(c);
											tokenizer.getNextToken("ID", "SCHEME", currentLine);
										}
										else if (isalnum(fileContents.peek())) {
											fileContents.get(c);
											string id = "SCHEME";
											id += c;
											tokenizer.getNextToken("ID", id, currentLine);
										}
									}
									else if (isspace(fileContents.peek())) {
										fileContents.get(c);
										tokenizer.getNextToken("ID", "SCHEM", currentLine);
									}
									else if (isalnum(fileContents.peek())) {
										fileContents.get(c);
										string id = "SCHEM";
										id += c;
										tokenizer.getNextToken("ID", id, currentLine);
									}
								}
								else if (isspace(fileContents.peek())) {
									fileContents.get(c);
									tokenizer.getNextToken("ID", "SCHE", currentLine);
								}
								else if (isalnum(fileContents.peek())) {
									fileContents.get(c);
									string id = "SCHE";
									id += c;
									tokenizer.getNextToken("ID", id, currentLine);
								}
							}
							else if (isspace(fileContents.peek())) {
								fileContents.get(c);
								tokenizer.getNextToken("ID", "SCH", currentLine);
							}
							else if (isalnum(fileContents.peek())) {
								fileContents.get(c);
								string id = "SCH";
								id += c;
								tokenizer.getNextToken("ID", id, currentLine);
							}
						}
						else if (isspace(fileContents.peek())) {
							fileContents.get(c);
							tokenizer.getNextToken("ID", "SC", currentLine);
						}
						else if (isalnum(fileContents.peek())) {
							fileContents.get(c);
							string id = "SC";
							id += c;
							tokenizer.getNextToken("ID", id, currentLine);
						}
					}
					else if (isalnum(fileContents.peek())) {
						fileContents.get(c);
						string id = "S";
						id += c;
						tokenizer.getNextToken("ID", id, currentLine);
					}
					else {
						tokenizer.getNextToken("ID", "S", currentLine);
					}
					break;
				case 'F':			//FACTS
					if (fileContents.peek() == 'a') {
						fileContents.get(c);
						if (fileContents.peek() == 'c') {
							fileContents.get(c);
							if (fileContents.peek() == 't') {
								fileContents.get(c);
								if (fileContents.peek() == 's') {
									fileContents.get(c);
									tokenizer.getNextToken("FACTS", currentLine);
								}
								else if (isspace(fileContents.peek())) {
									fileContents.get(c);
									tokenizer.getNextToken("ID", "Fact", currentLine);
								}
								else if (isalnum(fileContents.peek())) {
									fileContents.get(c);
									string id = "Fact";
									id += c;
									tokenizer.getNextToken("ID", id, currentLine);
								}
							}
							else if (isspace(fileContents.peek())) {
								fileContents.get(c);
								tokenizer.getNextToken("ID", "Fac", currentLine);
							}
							else if (isalnum(fileContents.peek())) {
								fileContents.get(c);
								string id = "Fac";
								id += c;
								tokenizer.getNextToken("ID", id, currentLine);
							}
						}
						else if (isspace(fileContents.peek())) {
							fileContents.get(c);
							tokenizer.getNextToken("ID", "Fa", currentLine);
						}
						else if (isalnum(fileContents.peek())) {
							fileContents.get(c);
							string id = "Fa";
							id += c;
							tokenizer.getNextToken("ID", id, currentLine);
						}
					}
					else if (isalnum(fileContents.peek())) {
						fileContents.get(c);
						string id = "F";
						id += c;
						tokenizer.getNextToken("ID", id, currentLine);
					}
					else {
						tokenizer.getNextToken("ID", "F", currentLine);
					}
					break;
				case 'R':			//RULES
					if (fileContents.peek() == 'u') {
						fileContents.get(c);
						if (fileContents.peek() == 'l') {
							fileContents.get(c);
							if (fileContents.peek() == 'e') {
								fileContents.get(c);
								if (fileContents.peek() == 's') {
									fileContents.get(c);
									tokenizer.getNextToken("RULES", currentLine);
								}
								else if (isspace(fileContents.peek())) {
									fileContents.get(c);
									tokenizer.getNextToken("ID", "Rule", currentLine);
								}
								else if (isalnum(fileContents.peek())) {
									fileContents.get(c);
									string id = "Rule";
									id += c;
									tokenizer.getNextToken("ID", id, currentLine);
								}
							}
							else if (isspace(fileContents.peek())) {
								fileContents.get(c);
								tokenizer.getNextToken("ID", "Rul", currentLine);
							}
							else if (isalnum(fileContents.peek())) {
								fileContents.get(c);
								string id = "Rul";
								id += c;
								tokenizer.getNextToken("ID", id, currentLine);
							}
						}
						else if (isspace(fileContents.peek())) {
							fileContents.get(c);
							tokenizer.getNextToken("ID", "Ru", currentLine);
						}
						else if (isalnum(fileContents.peek())) {
							fileContents.get(c);
							string id = "Ru";
							id += c;
							tokenizer.getNextToken("ID", id, currentLine);
						}
					}
					else if (isalnum(fileContents.peek())) {
						fileContents.get(c);
						string id = "R";
						id += c;
						tokenizer.getNextToken("ID", id, currentLine);
					}
					else {
						tokenizer.getNextToken("ID", "R", currentLine);
					}
					break;
				case 'Q':			//QUERIES
					if (fileContents.peek() == 'u') {
						fileContents.get(c);
						if (fileContents.peek() == 'e') {
							fileContents.get(c);
							if (fileContents.peek() == 'r') {
								fileContents.get(c);
								if (fileContents.peek() == 'i') {
									fileContents.get(c);
									if (fileContents.peek() == 'e') {
										fileContents.get(c);
										if (fileContents.peek() == 's') {
											fileContents.get(c);
											tokenizer.getNextToken("QUERIES", currentLine);
										}
										else if (isspace(fileContents.peek())) {
											fileContents.get(c);
											tokenizer.getNextToken("ID", "Querie", currentLine);
										}
										else if (isalnum(fileContents.peek())) {
											fileContents.get(c);
											string id = "Querie";
											id += c;
											tokenizer.getNextToken("ID", id, currentLine);
										}
									}
									else if (isspace(fileContents.peek())) {
										fileContents.get(c);
										tokenizer.getNextToken("ID", "Queri", currentLine);
									}
									else if (isalnum(fileContents.peek())) {
										fileContents.get(c);
										string id = "Queri";
										id += c;
										tokenizer.getNextToken("ID", id, currentLine);
									}
								}
								else if (isspace(fileContents.peek())) {
									fileContents.get(c);
									tokenizer.getNextToken("ID", "Quer", currentLine);
								}
								else if (isalnum(fileContents.peek())) {
									fileContents.get(c);
									string id = "Quer";
									id += c;
									tokenizer.getNextToken("ID", id, currentLine);
								}
							}
							else if (isspace(fileContents.peek())) {
								fileContents.get(c);
								tokenizer.getNextToken("ID", "Que", currentLine);
							}
							else if (isalnum(fileContents.peek())) {
								fileContents.get(c);
								string id = "Que";
								id += c;
								tokenizer.getNextToken("ID", id, currentLine);
							}
						}
						else if (isspace(fileContents.peek())) {
							fileContents.get(c);
							tokenizer.getNextToken("ID", "Qu", currentLine);
						}
						else if (isalnum(fileContents.peek())) {
							fileContents.get(c);
							string id = "Qu";
							id += c;
							tokenizer.getNextToken("ID", id, currentLine);
						}
					}
					else if (isalnum(fileContents.peek())) {
						fileContents.get(c);
						string id = "Q";
						id += c;
						tokenizer.getNextToken("ID", id, currentLine);
					}
					else {
						tokenizer.getNextToken("ID", "Q", currentLine);
					}
					break;
				case '\'':			//STRING
					str += '\'';
					while (inString) {
						c = fileContents.peek();
						if (c != '\'' && !fileContents.eof()) {
							str += c;
							fileContents.get(c);
						}
						else if (c == '\'') {	//Found a quote
							fileContents.get(c);
							char d = fileContents.peek();
							if (d != '\'') {	//single closing quote
								inString = false;
								str += '\'';
								tokenizer.getNextToken("STRING", str, currentLine);
							}
							else if (d == '\''){	//double quotes
								str = str + c + c;
								fileContents.get(c);
							}
						}
						else if (fileContents.eof()){	//c = EOF
							tokenizer.getNextToken("UNDEFINED", str, currentLine);
							inString = false;
						}
					}
					break;
				case '#':			//COMMENT (or block comment, same token)
					str += '#';
					c = fileContents.peek();
					if (c == '|') {	//Block comment
						str += '|';
						fileContents.get(c);
						bool sent = false;
						while (!fileContents.eof()) {
							fileContents.get(c);
							if (c != '|') {
								if (c != '\n') {
									str += c;
								}
								else {
									linesAdvanced++;
									str += ' ';
								}
							}
							else if (c == '|') {
								str += '|';
								c = fileContents.peek();
								if (c == '#') {
									fileContents.get(c);
									str += '#';
									tokenizer.getNextToken("COMMENT", str, currentLine);
									currentLine = currentLine + linesAdvanced;
									sent = true;
									break;
								}
								else {
									fileContents.get(c);
									if (c != '\n') {
										str += c;
									}
									else {
										str += ' ';
										linesAdvanced++;
									}
								}
							}
						}
						if (!sent) {
							tokenizer.getNextToken("UNDEFINED", str, currentLine);
						}
					}
					else {			//Line comment
						if (c != '\n') {
							str += c;
						}
						else {
							tokenizer.getNextToken("COMMENT", str, currentLine);
							break;
						}
						while (!fileContents.eof()) {
							fileContents.get(c);
							if (c != '\n') {
								str += c;
							}
							else {
								tokenizer.getNextToken("COMMENT", str, currentLine);
								break;
							}
						}
					}
					break;
				default:			//ID or UNDEFINED
					if (isalpha(c)) {
						string id = "";
						id += c;
						while (!isspace(c) && isalnum(c)) {
							c = fileContents.peek();
							if (!isspace(c) && isalnum(c)) {
								fileContents.get(c);
								id += c;
							}
						}
						tokenizer.getNextToken("ID", id, currentLine);
					}
					else {
						tokenizer.getNextToken("UNDEFINED", c, currentLine);
					}
				}
			}
		} while (c != EOF);

		tokens = tokenizer.sendTokens();
		return tokens;
	}
};
