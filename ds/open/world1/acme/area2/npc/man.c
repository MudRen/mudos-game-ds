#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "人妖", ({ "monster man","man", "__GUARD__" }) );
           set("level",12);
           set("combat_exp",1200);
        set("gender","無性");
       set("evil",35);
set("long" ,"他是一位半人半妖的怪物，面目猙獰，十分恐佈。\n");
        set("age",25);
           set_skill("unarmed",24);
           set_skill("parry",24);
           set_skill("dodge",24);
            set("attitude","killer");
        setup();
}
