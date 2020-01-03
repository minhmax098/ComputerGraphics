#include <stdio.h>

void Swap(int &a, int &b)
{
	a^=b;
	b^=a;
	a^=b;
}

void Swap1(int *a, int *b)
{
	*a=(*a)^(*b);
	*b=(*b)^(*a);
	*a=(*a)^(*b);
}

void Swap2(int &a, int &b)
{
	a=a+b; printf("\n trong ham a=%d, b=%d",a,b);
	b=a-b;
	a=a-b;
}

main()
{
	int a=2000000000, b=1500000000;
	
	printf("\n a=%d, b=%d",a,b);
	Swap(a,b);
	printf("\n a=%d, b=%d",a,b);
	Swap1(&a,&b);
	printf("\n a=%d, b=%d",a,b);
	Swap2(a,b);
	printf("\n a=%d, b=%d",a,b);
	
	
}
