#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "潑猴" , ({ "ruffian monkey","monkey", "__GUARD__" }) );
        set("level",6);
           set("combat_exp",600);
        set("age",8);
       set("evil",18);
        set("gender","雄性");
        set("race","野獸");
            set("attitude","killer");
        set("long","這是一隻活蹦亂跳的猴子。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
