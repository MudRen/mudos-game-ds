#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "啄木鳥" , ({ "woodpecker" }) );
        set("level",13);
        set("race","野獸");
        set("age",3);
        set("long","這是一隻正在努力找蟲吃的啄木鳥。\n");
        set("limbs", ({ "頭部", "身體", "尾巴" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
}


