#include <ansi.h>
inherit NPC;
void create()
{
        set_name("護院弟子",({ "guard" }) );
        set("long",@LONG
這裡的護院弟子, 是經過挑選出來, 有一定的武功水準, 負責王府的
安全.
LONG    
);
        set("race","人類");
        set("age",28);
        set("level",22);
        set("attitude","friendly");
        set_skill("dodge",40);
        set_skill("unarmed",70);
        set_skill("parry",40);
         setup();
        
}

