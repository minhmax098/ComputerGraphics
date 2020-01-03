#include <winbgim.h>

int main() 
{
	int i, j, k;
	
	initwindow(1200,600);
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			for (k=0; k<3; k++){
				settextstyle(i,j,k);
				outtextxy(0,i*j+k,"A");
			}
	getch();
	closegraph();
}
