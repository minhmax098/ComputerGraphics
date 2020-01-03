#include <winbgim.h> 
#define MAX 20

main()
{
	int n=5, p[MAX]={10,10,120,200,300,450,200,200,10,10},
	     HCN[MAX]={100,100,100,450,400,450,400,100,100,100};
	
	initwindow(300, 300);
	setbkcolor(14); cleardevice(); 
	//setcolor(1);
	//drawpoly(n,HCN);delay(10);
	setcolor(1);
	drawpoly(n,p);
	//rectangle(HCN[0],HCN[1],HCN[4],HCN[5]);
	getch();closegraph();
}
