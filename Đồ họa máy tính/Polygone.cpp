#include <stdio.h>
#include <winbgim.h>
#include <stdlib.h>
#include <time.h>
	
main()
{
	int i, n=5, P[12]; //P={0,0,... };
	
	srand(time(NULL));
	printf("Cac toa do da giac:");
	for (i=0; i<2*n; i++){
		P[i]=rand()%500 -250;
		printf("%d ",P[i]);
	} 
	P[2*n]=P[0];
	P[2*n+1]=P[1];
	initwindow(1300,700);
	setviewport(650,350,1300,700,0);
	setbkcolor(15); cleardevice();
	setcolor(1); drawpoly(n+1,P);
	setfillstyle(1,5);
	delay(100);	fillpoly(n+1,P);
	getch();
	//closegraph();
}
