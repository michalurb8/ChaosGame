#include "Pixel.h"
#include "Image.h"
#include <cmath>

#include "Vec2.h"

#define N 3
#define STEP 0
#define COUNT 0
#define COEFF 1
#define ACC 10000000

int main()
{
    srand(time(NULL));
    const int width = 1000, height = 1000;
    Image image(width, height);
    unsigned int rad = std::min(width, height)/2 - 50, ind;
    Vec2 point[N], current;
    for(int i = 0; i < N; ++i)
    {
        point[i].xPos =  width/2 + rad*sin(i*2*M_PI/N);
        point[i].yPos = height/2 + rad*cos(i*2*M_PI/N);
    }
    current = point[0];
    for(int i = 0; i < ACC; ++i)
    {
        ind = (STEP+ind+COEFF*rand()%(N-COUNT))%N;
        current.Move(point[ind]);
        image.SetPixel(current.xPos, current.yPos, 0, 255, 0);
    }
    image.Export("chaos");
    return 0;
}