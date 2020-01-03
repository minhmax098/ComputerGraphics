#include <stdio.h>
#include <winbgim.h>

#define FACT  0.866 //sqrt(3)/2

void K(int,int,int,int,int);

main()
{
      int mx,my,n;
      
      printf("n="); scanf("%d",&n);
	  initwindow(1300,700);
      mx=getmaxx(); my=getmaxy();
      setbkcolor(15); setcolor(1); cleardevice();
      K(n,0,my-150,mx,my-150);
      getch();
      closegraph();
}

void K(int n,int a,int b,int c,int d) 
{   
	int u,v;
	if (n>0){
		u=int(a+(c-a)/ 2+FACT*(d-b)/3); v=int(b+(d-b)/2+FACT*(a-c)/3); 
		K(n-1,a,b,a+(c-a)/3,b+(d-b)/3); 	
		K(n-1,a+(c-a)/3,b+(d-b)/3,u,v);
		K(n-1,u,v,a+2*(c-a)/3,b+2*(d-b)/3);	
		K(n-1,a+2*(c-a)/3,b+2*(d-b)/3,c,d);	
	} else line(a,b,c,d);
}
