#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
void drawEllipse(float x, float y, float z)
{
float end = 1000;
float p = end / (end + z);
x = 300 - x * p;
y = 250 + y * p;
ellipse(x, y, 270, 360, 2, 1);
}
int main()
{
int gd = 0, gm;
float i,j,radToDeg, proj_angle;
char ch=248;
int x, y, z, r = 150, count = 0;
initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
radToDeg = M_PI / 180, proj_angle = 315;
while (!kbhit())
{
count++;
printf("Figure:%d\nAngle of Projection: %.1f%c\n\n", count, proj_angle, ch);
for (i = 0; i < 180; i += 2.5)
{
// one complete circle using ellipse
for (j = 0; j < 360; j += 0.5)
{
x = r * cos(radToDeg * j) * sin(radToDeg * i);
y = r * sin(radToDeg * j) * sin(radToDeg * i);
z = r * cos(radToDeg * i);
// rotation
y = y * cos(radToDeg * proj_angle) - z * sin(radToDeg * proj_angle);
z = y * sin(radToDeg * proj_angle) + z * cos(radToDeg * proj_angle);
drawEllipse(x, y, z);
}
}
delay(5);
cleardevice();
proj_angle += 90;
if (proj_angle > 360)
{
proj_angle -= 360;
}
}
getch();
closegraph();
return 0;
}