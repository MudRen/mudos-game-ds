#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "妖獸" , ({ "monster beasts", "beasts", "__GUARD__" }) );
        set("level",10);
       set("gender","無性");
        set("age",10);
           set("combat_exp",1000);
        set("race","野獸");
           set("attitude","killer");
       set("evil",20);
        set("long","這是一隻長得怪異的怪獸，有翅膀，有四肢，有尾巴，有鳥嘴，有牛角的怪物。\n");
        set("limbs", ({ "頭部", "身體", "翅膀", "尾巴","角","前腳","後腳" }) );
        set("verbs", ({ "claw", "poke","hoof","crash","bite" }) );
        setup();
}
