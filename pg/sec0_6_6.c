#include <stdio.h>
#include <stdlib.h>

int global = 0;

int callee(int x, int y) {
	int local = x + y;
	return local + 1;
}

void caller(void) {
	global = callee(3, 4);
}

int main() {
	caller();

	return 0;
}
