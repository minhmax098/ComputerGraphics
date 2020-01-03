#include <stdio.h>
#include <winbgim.h>

main()
{
	char s[10];     
    
	initwindow(200,200);
	circle(100,100,50);
	printf("Thu nhap de cho 1..."); gets(s);
	
	initwindow(500,500);
    setbkcolor(15); setcolor(1); cleardevice();
    rectangle(100,100,200,200);
    printf("Thu nhap de cho 2..."); gets(s);
    closegraph();
	initwindow(500,500);
    setbkcolor(14); setcolor(1); cleardevice();
    line(10,10,200,200);	
    printf("Thu nhap de cho 3..."); gets(s);
    closegraph();
}
