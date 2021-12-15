#include "pch.h"
#include <iostream>

#pragma warning (disable : 4996)

int main()
{
	int x = 7;
	int y = 3;
	int *p;
	
	p = &x;
	printf("%p %d\n", p, *p);
	
	*p = *p + x + y;
	printf("%p %d\n", p, *p);
	
	p = &y;
	printf("%p %d\n", p, *p);

	*p = *p + x + y;
	printf("%p %d\n", p, *p);
}
