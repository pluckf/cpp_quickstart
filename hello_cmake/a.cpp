#include <iostream>
#include "b.h"
int main() {
    int a = 5;
	int b = 10;
	int c = addss(a, b);
	std::cout << "The sum of " << a << " and " << b << " is " << c << std::endl;
	return 0;
}
