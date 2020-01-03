void MLine1(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	c=getcolor();
	dx=x2-x1; dy=y2-y1;
	p=dy-dx/2; pkt=dy;  pt=dy-dx;
	for (x=x1, y=y1; x<=x2; x++){
		putpixel(x, y,c); 
		delay(1);
		if (p<0) p+=pkt;
		else {
			p+=pt;
			y++;
		}
	} 
}

void MLine2(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	c=getcolor();
	dx=x2-x1; dy=y2-y1;
	p=dx-dy/2; pkt=dx;  pt=dx-dy;
	for (x=x1, y=y1; y<=y2; y++){
		putpixel(x, y, c); 
		delay(1);
		if (p<0) p+=pkt;
		else {
			p+=pt;
			x++;
		}
	} 
}

void MLine3(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pg, pkg;
	
	c=getcolor();
	dx=x2-x1; dy=y2-y1;
	p=-dy-dx/2; pkg=-dy;  pg=-dy-dx;
	for (x=x1, y=y1; x<=x2; x++){
		putpixel(x, y, c); 
		delay(1);
		if (p<0) p+=pkg;
		else {
			p+=pg;
			y--;
		}
	} 
}

void MLine4(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	c=getcolor();
	dx=x2-x1; dy=y2-y1;
	p=dx+dy/2; pkt=dx;  pt=dx+dy;
	for (x=x1, y=y1; y>=y2; y--){
		putpixel(x, y, c); 
		delay(1);
		if (p<0) p+=pkt;
		else {
			p+=pt;
			x++;
		}
	} 
}

void MLine (int x1, int y1, int x2, int y2)
{
    int x,y,c,tam;
    float m;

	c=getcolor();
	if (x1>x2){
				tam=x1; x1=x2; x2=tam;
				tam=y1; y1=y2; y2=tam;
	}
 	if (y1==y2){
 		y=y1;
 		for (x=x1; x<=x2;x++) putpixel(x,y,c); 
	}
	else if (x1==x2){
 		x=x1;
 		if (y1<y2) for (y=y1; y<=y2;y++) putpixel(x,y,c); 
 		else for (y=y2; y<=y1;y++) putpixel(x,y,c); 
 	}
	else {
		m=float(y2-y1)/float(x2-x1);
		if (m==1) for (x=x1; x<=x2;x++,y++) putpixel(x,y,c); 
		if (m==-1) for (x=x1; x<=x2;x++,y--) putpixel(x,y,c); 
		if (m!=1 && m!=-1){
	    	if (m>0 && m<1) MLine1(x1,y1,x2,y2);
			if (m>1) MLine2(x1,y1,x2,y2);
			if (m<0 && m>-1) MLine3(x1,y1,x2,y2);
			if (m<-1) MLine4(x1,y1,x2,y2);
		}
	}
}
