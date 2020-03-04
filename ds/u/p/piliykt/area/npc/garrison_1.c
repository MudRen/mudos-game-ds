#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "巡邏官兵" , ({ "garrison" }) );
        set("level", 32);
        set("race","人類");
        set("gender","男性");
        set("age",35);
        set("int", 20);
        set("str", 50);
        set("con", 45);
        set_skill("sword", 70);
        set_skill("parry", 40);
        set_skill("unarmed", 60);
        set_skill("dodge", 45);
        set("long",
   "負責守衛大神木的巡邏官兵,他的職位就是保護大神木,不讓人靠近大神木。\n");
            (: random_move :),
 
       setup();

        carry_object(__DIR__"wp/longsword")->wield();
}


