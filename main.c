#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

#define DENSITY_THRESHOLD 0.2

void initiateMap(Map *map, int height, int width){
    map->height = height ;
    map->width = width ;
    map->matrix = (int **)malloc(height*sizeof(int *)) ;

    if (map->matrix == NULL){
        perror("Failed to allocate memory for matrix rows");
        exit(EXIT_FAILURE);
    }

    for(int i = 0 ; i<height ; i++){
        map->matrix[i] = (int *)malloc(width*sizeof(int));
        if (map->matrix[i] == NULL){
            perror("Failed to allocate memory for matrix ligns");
            exit(EXIT_FAILURE);
        }
    };

    // Initialize matrix with zeros
    for(int i=0 ; i<height ; i ++){
        for(int j=0 ; j<width ; j++){
            map->matrix[i][j] = 0 ;
        }
    }
}

void destroyMap(Map* map){
    for(int i = 0 ; i <map->height ; i ++){
        free(map->matrix[i]);
    };
    free(map->matrix);
}

void initializeRandomMap(Map* map){
    srand((unsigned int)time(NULL));
    int filledCells = 0 ;
    int totalCells = map->height*map->width ;
    double instantDensity = 0.0 ;

    while (instantDensity < DENSITY_THRESHOLD){    
        int random_x = rand()%map->width;
        int random_y = rand()%map->height;

        if (random_x%5 == 0){
            filledCells = buildSquare(map,random_x,random_y,rand()%max(1,min(min(random_x,map->width-random_x)*2,min(random_y,map->height-random_y))), filledCells);
        }
        if (random_x%5 == 1){
            filledCells = buildRectangle(map,random_x,random_y,(rand()%max(1,min(random_x,map->width-random_x))),(rand()%(map->height-random_y)), filledCells);
        }
        else {
            filledCells = buildCircle(map,random_x,random_y,rand()%max(1,(min(min(random_x,random_y),min(map->width-random_x,map->height-random_y)))), filledCells);
        }

        instantDensity = (double)filledCells/totalCells;
        //printf("%.2f (%d/%d)\n", instantDensity, filledCells, map->height * map->width);
    }
}

int buildRectangle(Map* map, int x, int y, int length, int height, int filledCells){
    for (int j = y ; j<y+height ; j++){
        for (int i = x-length ; i <x+length ; i++){
            if (map->matrix[j][i] == 0){
                filledCells++;
            }
            map->matrix[j][i] = 1;
        }
    }
    return filledCells ;
}


int buildCircle(Map* map, int x, int y, int radius, int filledCells){
    for (int i = x-radius ; i<x+radius ; i ++){        
            for (int j = y-radius ; j<y+radius ; j ++){
                int squared_distance = (i-x)*(i-x)+(j-y)*(j-y) ;
                if (squared_distance<radius*radius){
                    if (map->matrix[j][i] == 0){
                        filledCells ++;
                    }
                    map->matrix[j][i]=1;
                }
            }
    }
    return filledCells;
}

int buildSquare(Map* map, int x, int y, int length, int filledCells){
    for (int j = y ; j<=y+length ; j++){
        for (int i = x-length ; i <=x+length ; i++){
            if (map->matrix[j][i] == 0){
                filledCells += 1 ;
            }
            map->matrix[j][i] = 1;
        }
    }
    return filledCells ;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(){
    FILE *file = fopen("matrix_output.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    Map myMap ;
    initiateMap(&myMap,500,300);
    initializeRandomMap(&myMap);

    for (int i=0;i<myMap.height;i++){
        for (int j=0;j<myMap.width;j++){
            fprintf(file, "%d ", myMap.matrix[i][j]);;
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
    destroyMap(&myMap);
    return 0;
}