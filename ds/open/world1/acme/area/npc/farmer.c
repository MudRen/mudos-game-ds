#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "農夫" , ({ "farmer" }) );
        set("level",10);
        set("race","人類");
         set("gender","男性");
        set_skill("parry", 20);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set("long",
                 "他是一位在田裡辛勤耕耘的農夫。\n");
        setup();
        carry_object(__DIR__"wp/hoe.c")->wield();
}
