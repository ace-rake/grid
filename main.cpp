#include "grid.hpp"
#include <iostream>

using namespace std;

int	main(void)
{
	grid<char>	test(5, 5);
	cout << test;
	test.insertAll('a');
	cout << test;
	string wow("1234");
	test.insertString(wow, 3);
	cout << test;
}