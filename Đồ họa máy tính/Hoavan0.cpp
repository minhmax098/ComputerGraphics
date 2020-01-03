#include <winbgim.h>

#define FACT  0.866 //sqrt(3)/2

void K(int,float,float,float,float);
void Snow(int,float,float,float);
void C(int,int,int,int,int);
void D(int,int,int,int,int);

main()
{
      int mx, my, n, x, y, R=20;
      
      initwindow(1320,710);
      mx=getmaxx(); my=getmaxy();
      y=my/2; n=5;
      setbkcolor(15); cleardevice();
      setcolor(1);
	  for (y=R;y<my; y+=2*R)
        for (x=R;x<mx; x+=2*R){
		  setcolor(COLOR(x,y,x));	
		  switch ((x+y)/R % 3){
		  	case 0: Snow(n,x,y,R); break;
		  	case 1: rectangle(x-R,y-R,x+R,y+R); C(2*n,x,y-R/2,x,y+R/2); break;
		  	case 2: rectangle(x-R,y-R,x+R,y+R); D(2*n,x,y-R/2,x,y+R/2); break;
		  }
		}
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
 	K(n,u, v,a,b);  K(n,c,d,u,v);  K(n,a,b,c,d);
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

void C(int n, int a, int b, int c, int d)
{
	if (n>0){
		C(n-1, a, b, (a+c+b-d)/2, (b+d+c-a)/2);
		C(n-1, (a+c+b-d)/2, (b+d+c-a)/2, c, d);
	} else line(a, b, c, d);
}

void D(int n, int a, int b, int c, int d)
{
	if (n>0){
		D(n-1, a, b, (a+c+b-d)/2, (b+d+c-a)/2);
		D(n-1, c, d, (a+c+b-d)/2, (b+d+c-a)/2);
	} else line(a, b, c, d);
}
