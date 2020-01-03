#include <winbgim.h>
#include <stdio.h>
 
int main(){
    int x, y;
    
	setbkcolor(1);
    initwindow(1300,700);
    setbkcolor(15);
    cleardevice();
    while (1){
        delay(1);
 
        if (ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN, x, y);
            printf("\nleft click : (%d,%d)", x, y);
        }
 
        if (ismouseclick(WM_LBUTTONUP)){
            getmouseclick(WM_LBUTTONUP, x, y);
            printf("\nleft up click : (%d,%d)", x, y);
        }
 
        if (ismouseclick(WM_LBUTTONDBLCLK)){
            getmouseclick(WM_LBUTTONDBLCLK, x, y);
            printf("\nleft double click : (%d,%d)", x, y);
        }
 
        if (ismouseclick(WM_RBUTTONDOWN)){
            getmouseclick(WM_RBUTTONDOWN, x, y);
            printf("\nright click : (%d,%d)", x, y);
        }
 
        if (ismouseclick(WM_RBUTTONUP)){
            getmouseclick(WM_RBUTTONUP, x, y);
            printf("\nright up click : (%d,%d)", x, y);
        }
 
        if (ismouseclick(WM_RBUTTONDBLCLK)){
            getmouseclick(WM_RBUTTONDBLCLK, x, y);
            printf("right double click : (%d,%d)", x, y);
        }
        if (ismouseclick(WM_MOUSEMOVE)){
            getmouseclick(WM_MOUSEMOVE, x, y);
            printf("\nmove : (%d,%d)n", x, y);
        }
    }
    system("pause");
    closegraph();
}
