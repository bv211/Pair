#include <iostream>
#include "Pair.h"

using namespace std;

int main() {
	setlocale(0, "");

	Pair<int, string> pair(4);
	pair.add(12, "Hello");
	pair[43] = "World"; // error.

	for (auto& item : pair) {
		cout << "key: " << item << endl
			<< "value: " << pair[item];
	}

	return 0;
}