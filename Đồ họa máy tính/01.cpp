#include <winbgim.h>
#include <stdio.h>

// ve giua cua so hinh vuong canh 2d

int main() 
{
	int d, mx=500, my=500;
	
	printf("d= "); scanf("%d", &d);
	initwindow(mx, my);
	setviewport(mx/2, my/2, mx, my, CLIP_OFF);
	rectangle(-d, -d, d, d);
	getch();
}
