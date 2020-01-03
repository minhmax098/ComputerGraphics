#include <winbgim.h>

#define FACT  0.866 //sqrt(3)/2

void K(int,float,float,float,float);
void Snow(int,float,float,float);

main()
{
      int mx, my, n, x, y, R=20;
      
      initwindow(1300,700);
      mx=getmaxx(); my=getmaxy();
      y=my/2; n=5;
      setbkcolor(15); cleardevice();
      setcolor(1);
	  for (y=R;y<my; y+=2*R)
        for (x=R;x<mx; x+=2*R)	Snow(n,x,y,R); 
	  getch();
      closegraph();
}

void Snow(int n, float x,float y,float R)
{
	float a,b,c,d,u,v;
	
	a=x-R*FACT; b=y-R/2;
	c=x+R*FACT; d=y-R/2;
	u=x; v=y+R;
	line(int(a),int(b),int(c),int(d)); line(int(c),int(d),int(u),int(v));
	line(int(u),int(v),int(a),int(b));
 	K(n,u, v,a,b);  K(n,c,d,u,v);  K(n,c,d,a,b);
}

void K(int n,float a,float b,float c,float d) 
{   
	float u,v;
	if (n>0){
		u=a+(c-a)/2+FACT*(d-b)/3; v=b+(d-b)/2+FACT*(a-c)/3; 
		K(n-1,a,b,a+(c-a)/3,b+(d-b)/3); 	
		K(n-1,a+(c-a)/3,b+(d-b)/3,u,v);
		K(n-1,u,v,a+2*(c-a)/3,b+2*(d-b)/3);	
		K(n-1,a+2*(c-a)/3,b+2*(d-b)/3,c,d);	
	} else line(int(a),int(b),int(c),int(d));
}
