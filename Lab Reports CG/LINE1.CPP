#include<stdio.h>
#include<graphics.h>
#include<math.h>
float rounf (float a);
void main(){
int gd=DETECT,gm;
int x1,y1,x2,y2,steps,k,dy,dx,x,y,;f
printf("Enter the first points:");
scanf("%d%d",&x1,&x2);
printf("Enter the second points:");
scanf("%d%d",&x2,&y2);
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
dy=y2-y1;
if(abs(dx)>abs(dy))
steps=abs(dx);
else
steps=abs(dy);
x=dx/steps;
y=dy/steps;
x=x1;
y=y1;
for(k=1;k<=steps;k++)
{
y+=y;
putpixel(round(x),round(y),WHITE);
}
outtextxy(200,20,"DDA");
outtextxy(x1+5,y1-5,"(x1,y1)");
outtextxy(x2+5,y2+5,"(x1,y2)");
getch();
closegraph();
}
float round(float a)
{
int b=a+0.5;
return b;
}