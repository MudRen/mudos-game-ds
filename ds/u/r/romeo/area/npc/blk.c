#include <ansi.h>
inherit NPC;
void create()
{
        set_name(BLK "黑"NOR"衣怪", ({ "blk" }) );
        set("level",30);
           set("combat_exp",4000);
         set("exp",1500);
set("long","這是身穿黑衣的邪惡妖怪，渾身充滿邪氣，看起來十分神祕，也是狠角色喔。\n");
;
        set("age",50);
        set("evil",70);
     set("title",WHT"五代"NOR);
        set("gender","男性");
        set("attitude","killer");
             set_skill("unarmed",70);
        set_skill("dodge",60);
                  set_skill("parry",80);
        setup();
        carry_object("/u/k/king/area/npc/eq/devil-necklace")->wear();
}
