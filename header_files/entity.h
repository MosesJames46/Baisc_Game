#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_math.h"

//All entities should have health and position.
typedef entity_struct Entity;
struct entity_struct{
    int health = 0;
    Position entity_position;
};

void init_entity();
void display_health();