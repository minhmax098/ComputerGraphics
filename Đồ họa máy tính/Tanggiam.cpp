#include <stdio.h>
main()
{
	 int a=2, b=3, c; 
	 c=a+2*b++; printf("\n%d %d %d",a,b,c);
	 a=5+a--; 	printf("\n%d %d %d",a,b,c);
	 b=c+++a++;	printf("\n%d %d %d",a,b,c);
	 b=c++ + ++a;	printf("\n%d %d %d",a,b,c);//???
}
