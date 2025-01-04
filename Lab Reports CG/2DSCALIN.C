#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(){
	int gd=DETECT,gm;
	int x1,y1,x2,y2,sx,sy,x3,y3,x4,y4;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("\nEnter the strating point of the line segment(x1,y1):");
	scanf("%d %d", &x1,&y1);
	printf("\nEnter the ending point of the line segment(x2,y2):");
	scanf("%d %d", &x2,&y2);
	printf("\nEnter scaling factors(sx,sy):");
	scanf("%f%f",&sx,&sy);
	setcolor(7);
	line(x1,y1,x2,y2);
	outtextxy(x2+5,y2,"Object");
		x3=x1*sx;
		y3=y1*sy;
		x4=x2*sx;
		y4=y2*Ssy;
	setcolor(15);
	line(x3,y3,x4,y4);
	outtextxy(x4+5,y4,"Image");
	getch();

}