#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "護衛官兵" , ({ "guard" }) );
        set("level", 25);
        set("race","人類");
        set("gender","男性");
        set("age",30);
        set_skill("sword", 50);
        set_skill("parry", 40);
        set_skill("unarmed", 70);
        set_skill("dodge", 55);
        set("long",
   "負責巡邏神木村的官兵,他的職位就是保護神木村的安全,不讓人在神木裡鬧事。\n");
            (: random_move :),
 
       setup();

        carry_object(__DIR__"wp/longsword")->wield();
}

