#include <ansi.h>
inherit NPC;
void create()
{
        set("title","滄陵派三十二代弟子" );
        set_name("小弟子" , ({ "shaman" }) );
        set("level",10);
        set("race","人類");
        set("gender","男性");
        set("age",18);
        set("long","滄陵派入門不久的新弟子。\n");
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("sword", 30);
        setup();
carry_object("/open/world1/acme/area/npc/wp/sword")->wield();
add_money("coin", 300);
}
