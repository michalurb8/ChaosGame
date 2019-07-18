#include "Pixel.h"
#include "Image.h"
#include <cmath>

#define N 3
#define STEP 0
#define ILE 0
#define COEFF 1

struct Vec2
{
    float xPos, yPos;
    Vec2(float xArg = 0, float yArg = 0)
    {
        xPos = xArg;
        yPos = yArg;
    }
    Vec2 Move(const Vec2& arg)
    {
        this->xPos = (this->xPos + arg.xPos)/2;
        this->yPos = (this->yPos + arg.yPos)/2;
        return *this;
    }
};
int main()
{
    srand(time(NULL));
    const int width = 700, height = 700;
    Image image(width, height);
    unsigned int rad = std::min(width, height)/2 - 50, ind;
    Vec2 point[N], current;
    for(int i = 0; i < N; ++i)
    {
        point[i].xPos =  width/2 + rad*sin(i*2*M_PI/N);
        point[i].yPos = height/2 + rad*cos(i*2*M_PI/N);
    }
    current = point[0];
    for(short i = 0; i < 100; ++i)
    {
        ind = (STEP+ind+COEFF*rand()%(N-ILE))%N;
        current.Move(point[ind]);
        image.SetPixel(current.xPos, current.yPos, 255, 255, 255);
    }
    image.Export("chaos");
    return 0;
}