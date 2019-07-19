#include "Pixel.h"
#include "Image.h"
#include <cmath>
#include <iostream>

#include "Vec2.h"

#define N 5
#define SHIFT 1
#define EXCLUDE 1
#define HISTORY 3
#define COEFF 1
#define ACC 20000000

int main()
{
    srand(time(NULL));
    const int width = 1000, height = 1000;
    Image image(width, height);
    image.SetAll(255,255,255);
    unsigned int rad = std::min(width, height)/2 - 50;
    unsigned int indices[HISTORY];
    unsigned int r, g, b;
    Vec2 point[N], current;
    for(int i = 0; i < N; ++i)
    {
        point[i].xPos =  width/2 + rad*sin(i*2*M_PI/N);
        point[i].yPos = height/2 + rad*cos(i*2*M_PI/N);
    }
    for(int i = 0; i < HISTORY; ++i)
    {
        indices[i] = 0;
    }
    current = point[0];
    for(unsigned int i = 0; i < ACC; ++i)
    {
        //indices[0] = (SHIFT+indices[0]+COEFF*rand()%(N-EXCLUDE))%N;
        if(indices[1] == indices[2])
        {
            indices[0] = rand()%3 == 0 ? indices[0] : (indices[0] + 2 + rand()%2)%5;
        }
        else
        {
            indices[0] = rand()%5;
        }
        
        current.Move(point[indices[0]]);

        r = (indices[0]+1)*255.0/N;
        g = (indices[1]+1)*255.0/N;
        b = 255.0 * (current.xPos + current.yPos)/(width + height);
        r = g = b = 0;
        //image.SetPixel(current.xPos, current.yPos, r, g, b);
        image.ChangePixel(current.xPos, current.yPos, 1,1,1);

        for(int j = HISTORY - 1; j > 0; --j)
        {
            indices[j] = indices[j-1];
        }
    }
    image.Export("chaos");
    return 0;
}