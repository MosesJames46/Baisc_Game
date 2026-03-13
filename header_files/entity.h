
#ifndef ENTITY_HEADER
#define ENTITY_HEADER
#include "game_math.h"
//All entities should have health and position.
void init_entity();
void display_health();

typedef struct entity_struct Entity;
struct Entity{
    int health;
    Position position;
};

#endif

