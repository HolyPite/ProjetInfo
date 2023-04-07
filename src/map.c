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

void fill_map(Map* map) {
    // Parcourir chaque cellule de la carte
    for (int y = 0; y < map->size; y++) {
        for (int x = 0; x < map->size; x++) {
            // Générer un nombre aléatoire entre 0 et 6 et affecter la couleur correspondante à la cellule de la carte aux coordonnées (x, y)
            set_map_value(map, x, y, rand() % 7);
        }
    }

    // Positionner le joueur 1 en bas à gauche de la carte
    set_map_value(map, 0, map->size - 1, PLAYER1);
    
    // Positionner le joueur 2 en haut à droite de la carte
    set_map_value(map, map->size - 1, 0, PLAYER2);
}

int main(int argc, char** argv){
srand(time(NULL));
}

