#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "水牛" , ({ "buffalo" }) );
        set("level",10);
        set("race","野獸");
        set("con", 19);
        set("age",6);
        set("long",
                 "這是一隻在田裡幫農夫犛田的牛。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}

