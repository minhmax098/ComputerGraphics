#include <winbgim.h>

main()
{
	int n=10,R=10,i;
	
	initwindow(1000,600);
	//setwritemode(XOR_PUT); khong tac dung voi hinh tron
	//setcolor(15); 
	while (!kbhit()){
		setcolor(15); 
		for (i=1;i<=n;i++){
			circle(500,300,i*R); delay(50);
		} 
		delay(500);
		setcolor(0); 
		for (i=n;i>0;i--){
			circle(500,300,i*R); delay(50);
		} 
		delay(500);
	}
}
