#include <ansi.h>
inherit NPC;
void create()
{
        set("title","袁家村" );
        set_name("村民" , ({ "villager" }) );
        set("level",10);
        set("race","人類");
        set("gender","男性");
        set("age",25);
        set("long","久居於此的村人。\n");
        set_skill("dodge", 20);
        setup();
carry_object("/open/world1/acme/area/npc/wp/sword")->wield();
add_money("coin", 300);
}
