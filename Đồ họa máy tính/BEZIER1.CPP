/* Chuong trinh ve duong cong Bezier */
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include "mouse1.inc"

#define NPOINTS 8

struct xycoord {
  double xcoord, ycoord;
};

/* Tra ve gia tri Factorial cua q (q!) */
double fact(int q)
{
  int c;
  double f = 1.0;
    for (c=q; c>1; c--)
      f *= (double)c;
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

void BezierFcn (double *x, double *y, double u, double coeff[],
                int n, struct xycoord p[])
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
  int i;
  double u, x, y;
  double coeff[20];

  for (i=0; i<npts; i++)
    coeff[i] = C(npts-1, i);

  for (i=0; i<=segments; i++)
  {
    u = (double) i / segments;
    BezierFcn(&x, &y, u, coeff, npts - 1, p);
    if (i==0)
      moveto(x, y);
    else
      lineto(x, y);
  }
}

void main()
{
  int gr_drive = DETECT, gr_mode, n, x, y;
  unsigned char lbutton = 0, rbutton = 0;
  struct xycoord pt[NPOINTS];
  char s[80]="Nhap nut trai chuot de chon toa do n=8 diem de ve";

  initgraph(&gr_drive, &gr_mode, "\\BC\\BGI");
  cleardevice();
  reset_mouse();
  show_mouse();
  setcolor(YELLOW);
  rectangle(0, 0, getmaxx(), getmaxy());
  outtextxy(100, 10, s);
  for (n=0; n<NPOINTS; n++)
  {
    do {
      get_mouse_button(&lbutton, &rbutton, &x, &y);
    } while (lbutton == 0 && rbutton == 0);
    pt[n].xcoord = x;
    pt[n].ycoord = y;
    hide_mouse();
    circle(x, y, 3);
    show_mouse();
    while (lbutton || rbutton)
      get_mouse_button(&lbutton, &rbutton, &x, &y);
  }
  setcolor(RED);
  hide_mouse();
  moveto(pt[0].xcoord, pt[0].ycoord);
  for (n=1; n<NPOINTS; n++)
    lineto(pt[n].xcoord, pt[n].ycoord);
  setcolor(YELLOW);
  drawBezier(pt, NPOINTS, 40);
  show_mouse();

  getch();
  closegraph();
}