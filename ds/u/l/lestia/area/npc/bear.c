#include <ansi.h>
inherit NPC;
void create()
{
        set_name("黑熊" , ({ "dark bear","bear","dark" }) );
        set("level",25);
        set("race","野獸");
set("verbs", ({"claw" }));
set("attitude","aggressive");
        set("gender","男性");
        set("age",35);
        set_skill("parry", 45);
        set_skill("unarmed", 30);
        set_skill("dodge", 45);
        set("long","一隻兇猛的動物。\n");
        setup();
}


