#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "麻雀" , ({ "sparrow" }) );
        set("level",1);
        set("race","野獸");
        set("age",1);
        set("dex",-1);
        set("long","這是一隻小小的麻雀。\n");
        set("limbs", ({ "頭部", "身體", "尾巴" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
}

