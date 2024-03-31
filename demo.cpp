#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h" // where Pause is found



void DisplayText(window& w, string text, int x, int y) {
    w.SetFont(18, BOLD | ITALICIZED, BY_NAME, "Arial");
    w.SetPen(BLACK);
    w.DrawString(x, y, text);
}

void drawhome(window& w, color c,color c1, int x, int y, int size) {
    w.SetPen(BROWN);
    w.SetBrush(c);
    
    w.DrawRectangle(x, y, x + size, y + size, FILLED);
    w.SetBrush(c1);
    w.DrawTriangle(x, y, x + size, y, x + size / 2, y - size / 2, FILLED);
}
void DrawPyramid(window& w, color c, int rx, int ry, int size) {

    w.SetPen(c);


    w.DrawLine(rx - size, ry, rx + size * 2, ry);
    w.DrawLine(rx - size, ry, rx, ry - size);
    w.DrawLine(rx, ry - size, rx + size * 3, ry - size);
    w.DrawLine(rx + size * 2, ry, rx + size * 3, ry - size);


    w.DrawLine(rx, ry - size * 2, rx - size, ry);
    w.DrawLine(rx, ry - size * 2, rx, ry - size);
    w.DrawLine(rx, ry - size * 2, rx + size * 2, ry);
    w.DrawLine(rx, ry - size * 2, rx + size * 3, ry - size);
}




void clearWindow(window& inwind)
{
    inwind.SetPen(WHITE);
    inwind.SetBrush(WHITE);
    inwind.DrawRectangle(0, 0, inwind.GetWidth(), inwind.GetHeight());
    DisplayText(inwind, "Please Press \"c\" for Cone and \"h\" for Home and \"r\" for rocket  and \"m\" for moon ", 225, 0);
    DisplayText(inwind, "Please Press \"t\" for Tree and \"p\" for pyramid and \"q\" for delete ", 300, 20);


}

void drawCone(window& w, int x1, int y1, color c1, color c2, int size)
{
    /// THE CONE

    int rad = size;
    int height = 3 * rad;

    w.SetBrush(c2);
    w.SetPen(c2, 5);
    w.DrawCircle(x1, y1, rad);

    w.SetBrush(c1);
    w.SetPen(c1, 5);
    w.DrawTriangle(x1 - rad - 5, y1, x1 + rad + 5, y1, x1, height + y1);
}

void drawRocket(window& w, int x, int y, color t, color r, int size) {
    int half_size = size / 2;
    int double_size = 2 * size;


    w.SetBrush(t);
    w.SetPen(t, 5);
    w.DrawTriangle(x, y + double_size, x, y + 3 * half_size, x - half_size, y + double_size);
    w.DrawTriangle(x + half_size, y + double_size, x + half_size, y + 3 * half_size, x + size, y + double_size);


    w.SetBrush(r);
    w.SetPen(r, 5);
    w.DrawRectangle(x, y, x + half_size, y + double_size, FILLED);


    w.SetBrush(t);
    w.SetPen(t, 5);
    w.DrawTriangle(x, y, x + half_size, y, x + half_size / 2, y - size);


}
void drawTree(window& w, color c, int rx, int ry, int size) {
    if (ry + 2 * size >= 700)
        ry -= 2 * size;
    if (rx + size >= 1200)
        rx -= size;
    if (ry - 2 * size <= 25)
        ry += 2 * size;
    if (rx - size <= 0)
        rx += size;
    w.SetBrush(BROWN);
    w.DrawRectangle(rx - size / 2, ry + size / 2, rx + size / 2, ry + 2 * size);
    w.SetBrush(c);
    w.DrawCircle(rx, ry, size);
}

void drawMoon(window& w, color c, int rx, int ry, int size) {
    if (ry + size >= 700)
        ry -= size;
    if (rx + size >= 1200)
        rx -= size;
    if (ry - size <= 20)
        ry += size;
    if (rx - size <= 0)
        rx += size;
    w.SetBrush(c);
    w.DrawCircle(rx, ry, size);
    w.SetBrush(WHITE);
    w.SetPen(WHITE);
    w.DrawCircle(rx + size, ry, size);
}



int main()
{
    window w(1200, 700, 5, 5);
    srand(time(0));
    //drawPyramid(w, 300, 400, 200, 200);

    DisplayText(w, "Please Press \"c\" for Cone and \"h\" for Home and \"r\" for rocket  and \"m\" for moon ", 225, 0);
    DisplayText(w, "Please Press \"t\" for Tree and \"p\" for pyramid and \"q\" for delete ", 300, 20);


    while (true)
 {
        

        char key;

        keytype ktInput = w.GetKeyPress(key);
       

        if (ktInput == ASCII) {
            if (key == 'c') {
                int s = 10+rand() % (100-10+1);
                int x = s+ rand() % ((1200-20-s) - s+1); // reference
                int y = s+21+ rand() % ((700 -3*s-20)- s-21 +1);
                drawCone(w, x, y, BROWN, PINK, s);
            }
            else if (key == 'h')
            {
                int size = 5 + rand() % (200 - 5 + 1);
                int x1 = 5 + rand() % ((1200-20)- size + 1);
                int y1 = (size / 2+21) + rand() % ((700 - size) - (size / 2+21) + 1);
                drawhome(w,BLACK,LIGHTSKYBLUE, x1, y1, size);
            }

           
            else if (key == 'r')
            {
                int edge = 20 + rand() % (90 - 20 + 1);
                int x = edge + rand() % (1200 - 3 * edge - 20);//reference is the point at the top of the rectangle and the bottom of the triangle 
                int y = edge + rand() % (700 - 4 * edge);
                drawRocket(w, x, y, LIGHTSKYBLUE, RED, edge);
            }
            else if (key == 't')
            {
                int size = 5 + rand() % (100 - 5 + 1);
                int x2 = 5 + rand() % (1205 - size + 1);
                int y2 = (size / 2) + rand() % ((705 - size) - (size / 2) + 1);

                drawTree(w, BROWN, x2, y2, size);

            }
            else if (key == 'm') {
                int size = 5 + rand() % (100 - 5 + 1);
                int x1 = 5 + rand() % (1205 - size + 1);
                int y1 = (size / 2) + rand() % ((705 - size) - (size / 2) + 1);
                drawMoon(w, (BLUE), x1, y1, size);

            }
            else if (key == 'p') {
                int size = rand() % 100;
                int x = rand() % (w.GetWidth() - size);
                int y = rand() % (w.GetHeight() - size);

                DrawPyramid(w, BLACK, x, y, size);


            }
            else if (key == 'q') {
                clearWindow(w);

            }
        }
    }

    return 0;
}
