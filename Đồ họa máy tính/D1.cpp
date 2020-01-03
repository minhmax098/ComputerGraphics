#include <winbgim.h>
#include <stdio.h>

void D(int n,int x1, int y1, int x2, int y2);

main()
{
	  int n;
	  
      printf("n="); scanf("%d",&n);
	  initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
      D(n, 700, 170, 700, 600);
      getch();
      closegraph();
}

void D(int n,int x1, int y1, int x2, int y2)
{
	if (n>0){
		D(n-1, x1, y1, (x1+x2+y1-y2)/2, (y1+y2+x2-x1)/2);
		D(n-1, x2, y2, (x1+x2+y1-y2)/2, (y1+y2+x2-x1)/2 );
	} else line(x1, y1, x2, y2);
}
