#include "game.h"
#include "../sound/sound.h"
#include "../texture/texture.h"
#include "../player/player.h"
#include "../monster/monster.h"

void game (void){
    sound();
    texture();
    player();
    monster();
    
}
