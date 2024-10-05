#include "../random.h"
#include "math.h"
#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

int calculateTime(unsigned radio);

int
main(void)
{
    randomize();

    printf("TIEMPO\tRADIO\nRELACION\n");
    printf("%d\t%d\n", calculateTime(2), 2);
    printf("%d\t%d\n", calculateTime(3), 3);
    printf("%d\t%d\n", calculateTime(4), 4);
    printf("%d\t%d\n", calculateTime(5), 5);
}

int calculateTime(unsigned radio){
    Point actualPosition = (Point) {.x=0, .y=0};
    int t = 0;

    static int directions[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (pow(actualPosition.x,2) + pow(actualPosition.y,2) < radio * radio )
    {
        int rand_dir = randInt(0, 3);

        actualPosition.x += directions[rand_dir][0];
        actualPosition.y += directions[rand_dir][1];

        t++;
    }

    return t;
}