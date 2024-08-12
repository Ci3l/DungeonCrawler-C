#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void initiateMap(Map *map, int height, int width){
    map->height = height ;
    map->width = width ;
    map->matrix = (int **)malloc(height*sizeof(int *)) ;

    if (map->matrix == NULL){
        perror("Failed to allocate memory for matrix rows");
        exit(EXIT_FAILURE);
    }
    for(int i = 0 ; i<width ; i++){
        map->matrix[i] = (int *)malloc(height*sizeof(int));
        if (map->matrix[i] == NULL){
            perror("Failed to allocate memory for matrix ligns");
            exit(EXIT_FAILURE);
        }
    };
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

int main(){
    Map myMap ;
    initiateMap(&myMap,5,5);
    myMap.matrix[2][2] = 3 ;
    myMap.matrix[3][3] = 3 ;
    for (int i=0;i<myMap.width;i++){
        for (int j=0;j<myMap.height;j++){
            printf("%d ",myMap.matrix[i][j]);
        }
        printf("\n");
    }
    destroyMap(&myMap);
    return 0;
}