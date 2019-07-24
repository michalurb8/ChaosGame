#include "Image.h"
#include <cmath>
#include <iostream>

#include "Vec2.h"

#define N 7
#define SHIFT 4
#define EXCLUDE N-SHIFT
#define HISTORY 1
#define COEFF 1
#define ACC1 5000000
#define ACC2 1

int main()
{
    srand(time(NULL));
    const int width = 500, height = 500;
    Image image(width, height);
    image.SetAll(0,0,0);
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
    for(unsigned long i = 0; i < ACC1; ++i)
    {
        for(unsigned long j = 0; j < ACC2; ++j)
        {
            indices[0] = (SHIFT+indices[0]+COEFF*rand()%(N-EXCLUDE))%N;
 
            current.Move(point[indices[0]]);
            //r = (indices[0]+1)*255.0/N;
            //g = 1;
            //b = (indices[1]+1)*255.0/N;

            //image.SetPixel(current.xPos, current.yPos, r, g, b);
            image.ChangePixel(current.xPos, current.yPos, 1, 0, 1);

            for(int k = HISTORY-1; k > 0; --k)
            {
                indices[k] = indices[k-1];
            }
        }
    }
    image.Export("chaos");
    return 0;
}
