#include <winbgim.h>

#define NPOINTS 7

struct xycoord {
  double xcoord, ycoord;
};

/* Tra ve gia tri Factorial cua q (q!) */
double fact(int q)
{
  int f=1, c;
    for (c=q; c>1; c--)
      f *= c;
    return (f);
}

double C(int n, int i)
{
  return (fact(n) / (fact(i) * fact(n-i)));
}

double blend(int i, int n, double u, double binomial)
{
  double partial;
  int j;

  partial = binomial;
  for (j=1; j<= i; j++)
    partial *= u;
  for (j=1; j<= (n-i); j++)
    partial *= (1.0 - u);
  return partial;
}

void BezierFcn (double *x, double *y, double u, double coeff[], int n, struct xycoord p[])
{
  int i;
  double b;

  *x = *y = 0;
  for (i=0; i<=n; i++)
  {
    b = blend (i, n, u, coeff[i]);
    *x += (b * p[i].xcoord);
    *y += (b * p[i].ycoord);
  }
}

void drawBezier(struct xycoord p[], int npts, int segments)
{
  int i, oldx, oldy;
  double u, x, y;
  double coeff[20];

  for (i=0; i<npts; i++)
    coeff[i] = C(npts-1, i);

  for (i=0; i<=segments; i++)
  {
    u = (double) i / segments;
    BezierFcn(&x, &y, u, coeff, npts - 1, p);
    if (i==0)
    {
      moveto(x, y);
      oldx = x;
      oldy = y;
    }
    else
    {
      lineto(x, y);
      oldx = x;
      oldy = y;
    }
  }
}


main()
{
  int mx, my, n;
  struct xycoord pt[] = { {400,270}, {400,120}, {100,120}, {100,540},
                          {510,480}, {475,270}, {600,270}};
  int order[] = {0, 1, 2, 3, 4, 5, 6};    
  initwindow(1000,600);
  setbkcolor(15);  cleardevice();
  mx=getmaxx(); my=getmaxy();
  setcolor(5);
  rectangle(0, 0, mx, my);
  for (int i=0; i<NPOINTS; i++){
  	circle(pt[i].xcoord, pt[i].ycoord,5);
  }
  setcolor(9);
  drawBezier(pt, NPOINTS, 40);
  getch();
  closegraph();
}



