#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
// Define a maximum number of vertices for the fixed-size array
#define MAX_VERTICES 10
int main()
{
int ver, face, n, j, i, poly[MAX_VERTICES*2];
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
printf("Enter the number of faces: ");
scanf("%d", &face);
n = face;
for (j = 0; face != j; face--)
{
printf("Enter the total number of vertices in face %d: ", n - face + 1);
scanf("%d", &ver);
printf("Enter vertices for face %d (x, y): \n", n - face + 1);
for (i = 0; i < (ver * 2); i++)
{
printf("\tx%d, y%d: ", i / 2, i / 2);
scanf("%d %d", &poly[i], &poly[i + 1]);
i++;
}
poly[ver * 2] = poly[0];
poly[(ver * 2) + 1] = poly[1];
setcolor(getmaxcolor());
setfillstyle(SOLID_FILL, n - face + 1);
fillpoly(ver + 1, poly);
printf("Vertices for face %d:\n", n - face + 1);
for (i = 0; i < (ver * 2); i += 2)
{
printf("(%d, %d)\n", poly[i], poly[i + 1]);
}
}
getch();
closegraph();
return 0;
}