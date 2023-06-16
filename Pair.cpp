#include <iostream>
#include "Pair.h"

using namespace std;

int main()
{
	Pair<int, string> pair(4);
	pair.add(12, "Hello");
	pair.add(43, "World");
	pair.add(12, "Kek"); // key 12 is exist
	pair.add(1, "Princes is in another castle");

	pair[12] = "HALO";
	cout << pair[12] << endl;
	cout << pair[43] << endl;
	cout << pair[1] << endl;
	cout << pair[0] << endl; // error, key is not exist

	return 0;
}