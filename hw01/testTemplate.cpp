#include "swapTemplate.h"
#include <iostream>

int main(void) {
	swapClass<int> swapInts;
	swapInts.var1 = 3;
	swapInts.var3 = 7;
	swapInts.swap13();

	printf("%d\n", swapInts.var3);
}
