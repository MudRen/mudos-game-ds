#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小狗" , ({ "dog"}) );
        set("level",5);
        set("race","野獸");
        set("gender","男性");
        set("age",35);
        set_skill("parry", 15);
set("verbs", ({ "hoof","claw" }));
        set_skill("unarmed", 10);
        set_skill("dodge", 15);
        set("long","一隻可愛的動物。\n");
        setup();
}


