#include <iostream>
#include <string>
#include "PostfixCalc.h"

using namespace std;

int main(void) {
	
	std::string input;
	double result;

	std::cout << "input : ";
	std::getline(std::cin, input);

	result = PostFixCalc(input);
	std::cout << "result : " << result << endl;

	return 0;
}