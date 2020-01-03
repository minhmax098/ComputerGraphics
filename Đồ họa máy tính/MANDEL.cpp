/* Mandelbrot */
#include <winbgim.h>
#include <math.h>

/* 1 / sqrt(2) */
#define FCT 0.7071067
/* he so doi tu do sang radian */
#define RADS 0.017453293


main()
{
  int k, l, n, color, mx, my;
  double xl = -2.0, xr = 0.6, yu = -1.2, yo = 1.2, dx, dy;
  double re, im, x, y, xalt, yalt, xm, ym;

  initwindow(1360,700);
  setbkcolor(15); setcolor(1); cleardevice();

  mx = getmaxx();
  my = getmaxy();
  dx = (xr - xl) / mx;
  dy = (yo - yu) / my;

  for (k=0; k<mx; k++)
  {
    re = xl + k * dx;
    for (l=0; l<my; l++)
    {
      im = yu + l * dy;
      x = 0; y = 0; n = 0;
      do {
        xalt = x;
        yalt = y;
        xm = xalt * xalt;
        ym = yalt * yalt;
        x = xm - ym + re;
        y = 2 * xalt * yalt + im;
        n++;
      } while (n<=120 && x*x + y*y <= 100);
      putpixel(k, l, n);
    }
  }
  getch();
  closegraph();
}

