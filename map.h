#ifndef MAP_H
#define MAP_H

typedef struct {
    int height ;
    int width ;
    int **matrix ;
} Map ;

void initiateMap(Map *map, int width, int height);
void destroyMap(Map *map);

#endif // MAP_H

