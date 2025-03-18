#include "Canvas.h"


// Constructor 
Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			a[i][j] = ' '; // empty canvas 
}


void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int centruX = x + ray, centruY = y + ray; //centruY și centruX reprezintă centrul cercului

	for (int i = x;i <= x + 2 * ray;i++)
		for (int j = y;j <= y + 2 * ray;j++)
			if (abs((i - centruX) * (i - centruX) + (j - centruY) * (j - centruY) - ray * ray) <= ray / 2) //calculează ecuația cercului în coordonatele carteziene și o desenează folosind caracterul dat, adică ch. calculează pătratul distanței de la punctul (i, j) la centrul cercului. Dacă este îndeplinită condiția înseamnă că punctul nostru este înăuntrul cercului
				a[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int centruX = x + ray, centruY = y + ray;
	for (int i = x;i <= x + 2 * ray;i++)
		for (int j = y;j <= y + 2 * ray;j++)
			if ((i - centruX) * (i - centruX) + (j - centruY) * (j - centruY) <= ray  * ray )
				a[i][j] = ch;
}


void Canvas::Print()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
			std::cout << a[i][j]<<' ';
		std::cout << std::endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			a[i][j] = ' ';
}
void Canvas::SetPoint(int x,int y,char ch)
{
   a[x][y]=ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++) {
		// laturile de pe verticala
		a[i][left] = ch;
		a[i][right] = ch;
	}
	for (int i = left;i <= right;i++) {
		// laturile de pe orizontala
		a[top][i] = ch;
		a[bottom][i] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top+1;i < bottom;i++)
		{
            for (int j = left+1;j <right;j++)
			     a[i][j] = ch; 
        }
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1), dy = -abs(y2 - y1);
    int sx;
    if(x1<x2)
      sx=1;
    else sx=-1;
    int sy;
    if(y1<y2)
      sy=1;
    else sy=-1;
	int err = dx + dy, e2;
	while (true) {
		a[x1][y1] = ch;
		if (x1 == x2 && y1 == y2) break;
		e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y1 += sy;
		}
        int dx = abs(x2 - x1), dy = -abs(y2 - y1);
        int sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1; 
	}
}
