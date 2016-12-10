#include "TXLib.h"

void car(int x, int y, int kapot, int kuzov, int koleso, int kabina);
void people();
void drawMountain();
void drawRoad();
void pervayaMashinaEdet();
void vtorayaMashinaEdet();
void checkWindowLimits(int *x, int *y);
int main()
{
    txCreateWindow(1300, 600);
    HDC fon = txLoadImage ("road.bmp");
    int x = 500;
    int y = 500;
    int speedX = 20;
    int speedY = 20;
    while(1)
    {
        txBitBlt (txDC(), 0, 0, 1300, 600, fon, 0, 0);

        // НИТРО
        if(GetAsyncKeyState(VK_SPACE))
        {
           x = x + speedX * 5;
        }

        //КНОПКИ
        if(GetAsyncKeyState(VK_LEFT)) {
           x = x - speedX;
        }
        if(GetAsyncKeyState(VK_RIGHT)) {
           x = x + speedX;
        }
        if(GetAsyncKeyState(VK_DOWN)) {
           y = y + speedY;
        }
        if(GetAsyncKeyState(VK_UP)) {
           y = y - speedY;
        }

        checkWindowLimits (&x, &y);
        car(x, y, 0, 0, 0, 0);
        txSleep(10);
}

    txDeleteDC (fon);

    return 0;
}




void vtorayaMashinaEdet()
{
   for (int i = 0; i < 140; i++)
    {
        txSetFillColour(RGB(28,172,227));
        txClear();

        drawMountain();
        drawRoad();

        car(1400 - 15*i, 310, 0, 0, 0, 0);

        txSleep(10);
    }
}

void checkWindowLimits(int *x, int *y)
{
    if (*x < 0)
    {
        *x = 0;
    }
    if (*x > txGetExtentX() - 390)
    {
        *x = txGetExtentX() - 390;
    }
    if (*y < 150)
    {
         *y = 150;
    }
    if (*y > txGetExtentY() - 40)
    {
        *y = txGetExtentY() - 40;
    }
}


void car (int x, int y, int kapot, int kuzov, int koleso, int kabina)
{

    // все квадраты
    txSetFillColour(TX_RED);
    txSetColour(TX_BLACK, 1);
    txLine     ( x- 20,  y-70-kapot,   x+180,         y-70);
    txRectangle( x- 20,  y- 70,        x+180,         y+10);
    txRectangle( x+180,  y-150-kabina, x+280,         y+10);
    txRectangle( x+280,  y- 80,        x+380+kuzov,   y+10);

    // окно
    txSetFillColour(TX_LIGHTCYAN);
    txRectangle( x+190,  y-140,        x+270,         y-80);

    // ручка двери
    txSetColour(TX_BLACK, 3);
    txSetFillColour(TX_LIGHTGRAY);
    txEllipse(   x+190,     y-60,      x+210,         y-50);

    // колёса
    txSetColour(TX_BLACK, 5);
    txSetFillColour(TX_GRAY);
    txCircle(    x+60,      y+10,      30+koleso);
    txCircle(    x+300,     y+10,      30+koleso);

    // диски
    txCircle(    x+60,      y+10,      10);
    txCircle(    x+300,     y+10,      10);

    // фары
    txSetColour(TX_ORANGE, 2);
    txSetFillColour(TX_YELLOW);
    txEllipse(   x+380,     y-20,      x+390,          y);
}


void drawMountain()
{
    txSetColour(TX_BLUE, 5);
    txLine(10, 250, 110, 90);
    txLine(110, 90, 150, 250);

    txLine(130, 180, 200, 60);
    txLine(200, 60, 240, 150);

    txLine(150, 250, 320, 70);
    txLine(320, 70, 380, 160);

    txLine(330, 250, 420, 100);
    txLine(420, 100, 540, 250);

    txLine(460, 150, 520, 80);
    txLine(520, 80, 650, 250);

    // солнце
    txSetColour(TX_ORANGE, 2);
    txSetFillColour(TX_YELLOW);
    txCircle(680, 50, 35);
}

void drawRoad()
{
    txSetFillColour(RGB(128,128,128));
    txSetColour(TX_BLACK, 1);
    txRectangle(0, 250, 1300, 600);

    txSetColour(TX_WHITE, 3);
    txLine     ( 0, 400, 1300,400);
    txSetColour(TX_WHITE, 3);
    txLine     ( 0, 410, 1300,410);

    /*txSetFillColour(RGB(240, 227, 66));
    txRectangle(0, 250, 1300, 600);*/
}

void people()
{
    txSetColour(TX_BLACK, 2);
    txSetFillColour(TX_BLUE);
    txLine(550, 320, 550, 370);
    txLine(550, 330, 520, 350);
    txLine(550, 330, 580, 350);
    txLine(550, 370, 530, 400);
    txLine(550, 370, 520, 400);
    txLine(660, 380, 660, 430);
    txLine(660, 390, 640, 420);
    txLine(660, 390, 680, 460);
    txLine(660, 480, 640, 460);
    txLine(660, 480, 680, 460);
    txLine(740, 280, 740, 330);
    txLine(740, 290, 720, 320);
    txLine(740, 290, 760, 320);
    txLine(740, 330, 720, 360);
    txLine(740, 330, 760, 360);

    txCircle(550, 310, 2);
    txCircle(660, 370, 2);
    txCircle(740, 270, 2);
}
