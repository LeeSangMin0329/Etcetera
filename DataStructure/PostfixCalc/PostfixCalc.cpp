#include <iostream>
#include <vector>
#include <sstream>
#include <assert.h>
#include <assert.h>

#include "PostfixCalc.h"
#include "StackUseLinkedList.h"

using namespace std;

double PostFixCalc(string input) {
	vector<string> parsor;
	stringstream sStream(input);
	string buf;

	StackUseLinkedList stack;
	
	while (sStream >> buf) {
		parsor.push_back(buf);
	}
	
	double element1;
	double element2;
	
	for (int i = 0; i < parsor.size(); i++) {
		if (parsor[i] == "+") {
			stack.Pop(&element2);
			stack.Pop(&element1);
			stack.Push(element1 + element2);
		}
		else if (parsor[i] == "-") {
			stack.Pop(&element2);
			stack.Pop(&element1);
			stack.Push(element1 - element2);
		}
		else if (parsor[i] == "*") {
			stack.Pop(&element2);
			stack.Pop(&element1);
			stack.Push(element1 * element2);
		}
		else if (parsor[i] == "/") {
			stack.Pop(&element2);
			stack.Pop(&element1);
			
			assert(element2 != 0); // Divide 0
			stack.Push(element1 / element2);
		}
		else {
			stack.Push(atof(parsor[i].c_str()));
		}
	}
	if (stack.Count() != 1) {
		cout << "Invalid input" << endl;
		exit(EXIT_FAILURE);
	}
	
	stack.Pop(&element1);
	return element1;
}