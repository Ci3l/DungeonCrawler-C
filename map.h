#ifndef MAP_H
#define MAP_H

typedef struct {
    int height ;
    int width ;
    int **matrix ;
} Map ;

void initiateMap(Map *map, int width, int height);
void destroyMap(Map *map);
void randomMapIniator(Map *map);
int buildCircle(Map *map,int x, int y, int radius, int filledCells);
int buildRectangle(Map *map,int x, int y, int length, int height, int filledCells);
int buildSquare(Map *map,int x, int y, int length, int filledCells);
int min(int a, int b);
int max(int a, int b);

#endif // MAP_H

