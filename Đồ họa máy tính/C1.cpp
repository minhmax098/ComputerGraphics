#include <winbgim.h>
#include <stdio.h>

void C(int,int, int, int, int);

main()
{
      int gd=0,gm,n;
      
      printf("n="); scanf("%d",&n);
	  initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
      C(n, 500, 200, 500, 500);
      getch();
      closegraph();
}

void C(int n,int a, int b, int c, int d)
{
	if (n>0){
		C(n-1, a, b, (a+b+c-d)/2, (b+c+d-a)/2);
		C(n-1, (a+b+c-d)/2, (b+c+d-a)/2, c, d);
	} else line(a, b, c, d);
}
