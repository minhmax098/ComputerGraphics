#include <stdio.h>
#include <stdlib.h>
main()
{
	int x, y, z, t, X, Y;
	
	
	system("Color F1"); system("CLS");
	printf("Nhap 4 so: "); scanf("%d%d%d%d",&x, &y, &z, &t);
	X= (x+z+t-y)/2;
	Y= (y+t-z+x)/2;
	printf("X=%d\nY=%d\n", X, Y);
	system("Pause");
}
