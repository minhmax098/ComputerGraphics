#include <stdio.h>
#include <winbgim.h>


int main() 
{
	int i, j, k; char s[10]="ABC";
	
	initwindow(1200,600);
	//setbkcolor(15); setcolor(1); cleardevice();
	circle(600,300,100);
	outtextxy(600,300,s);

	system("pause");
	closegraph();
}
