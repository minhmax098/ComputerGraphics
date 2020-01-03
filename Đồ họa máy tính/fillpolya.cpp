#include <winbgim.h>
#define MAX 20

main()
{
	int i, n=5, p[MAX]={100,100,120,200,300,450,200,200,100,100},
	     HCN[MAX]={100,100,100,450,400,450,400,100,100,100};
	
	initwindow(1000, 600);
	setbkcolor(15); cleardevice(); 
	setcolor(1);
	drawpoly(n,p);
	setcolor(5);
	drawpoly(n,HCN);
	getch();
	setcolor(2);
	moveto(HCN[0],HCN[1]);
	lineto(HCN[2],HCN[3]); getch();
	lineto(HCN[4],HCN[5]); getch();
	lineto(HCN[6],HCN[7]); getch();
	lineto(HCN[0],HCN[1]); getch();		
	setcolor(4);
	rectangle(HCN[0],HCN[1],HCN[4],HCN[5]);
	getch();
	setbkcolor(1);
	floodfill(200,200,4); getch();
	for (i=0; i<50; i++){
		setfillstyle(i,50-i); fillpoly(n,HCN);
		delay(500);
	}	
}
