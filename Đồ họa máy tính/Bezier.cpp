#include <stdio.h>
#include <string.h>
#include <winbgim.h>

#define MAX 20

struct point {
  double x, y;
};

double C(int n, int k)
{
  if (k==0||k==n) return 1;
  else return C(n-1,k-1)+C(n-1,k);
}

double blend(int i, int n, double u, double b)
{
  double p;
  int j;

  p = b;
  for (j=0; j< i; j++)
    p *= u;
  for (j=0; j<n-i; j++)
    p *=1-u;
  return p;
}

void BezierFcn (double &x, double &y, double u, double c[], int n, point p[])
{
  int i;
  double b;

  x = y = 0;
  for (i=0; i<=n; i++)
  {
    b = blend (i, n, u, c[i]);
    x += (b * p[i].x);
    y += (b * p[i].y);
  }
}

void drawBezier(point p[], int npts, int ns)
{
  int i;
  double u, x, y;
  double c[MAX];

  for (i=0; i<npts; i++)
    c[i] = C(npts-1, i);

  for (i=0; i<=ns; i++)
  {
    u = (double)i/ns;
    BezierFcn(x, y, u, c, npts - 1, p);
    if (i==0) moveto(x, y); else  lineto(x, y);
  }
}


main()
{
  int mx, my, x, y, n, np, i;
  
  point p[MAX]; char s[10], ss[10];
  
  printf("So diem kiem soat np ="); scanf("%d",&np);
  printf("So doan nho n ="); scanf("%d",&n);
  initwindow(1300,700);
  setbkcolor(15); setcolor(0); cleardevice();
  mx=getmaxx(); my=getmaxy();
  rectangle(0, 0, mx, my);
  settextjustify(0,1);
  settextstyle(0,0,2);
  i=0;
  while (i<np){
  	delay(1);
  	if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick (WM_LBUTTONDOWN,x,y);
			p[i].x=x;
			p[i].y=y;
			circle(x,y,3);
			strcpy(s,"P");
			itoa(i,ss,10);
			strcat(s,ss);
			outtextxy(x+4,y,s);
			i++;
	}
  }
  setcolor(1);
  drawBezier(p, np, n);
  getch();
  closegraph();
}
