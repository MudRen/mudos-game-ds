#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "巨熊" , ({ "big bear", "bear", "__GUARD__" }) );
        set("level",8);
        set("age",10);
           set("combat_exp",800);
       set("gender","雄性");
       set("evil",10);
        set("race","野獸");
              set("attitude","killer");
        set("long","這是一隻體形相當龐大的巨熊。\n");
        set("limbs", ({ "頭部", "身體", "尾巴","前腳","後腳" }) );
        set("verbs",({ "claw","crash","bite"}));
        setup();
}
