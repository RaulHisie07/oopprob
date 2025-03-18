#include "Canvas.cpp"

int main () {
    Canvas c = Canvas(20, 20);
    char contur = '*';
    c.DrawCircle(4, 4, 3, contur);
    c.Print();
    c.Clear();
    c.FillCircle(4, 4, 3, 'r');
    c.Print();
    c.Clear();
    c.DrawRect(4,3,7,9,contur);
    c.Print();
    c.SetPoint(5,5,contur);
    c.Print();
    c.Clear();
    c.DrawLine(4,3,20,20,'@');
    c.Print();
    return 0;
}