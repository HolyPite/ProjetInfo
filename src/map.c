#include "../head/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Map map = {.map = NULL, .size = 0};

void create_empty_map(Map* map, int size) {
    // Définir la taille de la carte avec la valeur size passée en argument
    map->size = size;
    
    // Allouer de la mémoire pour le tableau 2D de la carte sous forme d'un tableau 1D
    map->map = (Color*)malloc(size * size * sizeof(Color));
}


void set_map_value(Map* map, int x, int y, Color value) {
    // Affecter la couleur value à la cellule de la carte aux coordonnées (x, y)
    map->map[y * map->size + x] = value;
}

Color get_map_value (Map* map, int x, int y){
	if (map -> map == NULL || x > map -> size || y > map -> size)
	{
		printf("[ERROR] map not big enough or not initialized %p %i access (%i %i)", map -> map, map -> size, x, y);
		return ERROR;
	}
	return map -> map[y * map -> size + x];
}

void fill_map(Map* map){
}
int main(int argc, char** argv){
srand(time(NULL));
}

