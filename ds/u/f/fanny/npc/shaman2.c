#include <ansi.h>
inherit NPC;
void create()
{
        set("title","滄陵派三十一代弟子" );
        set_name("大弟子" , ({ "shaman" }) );
        set("level",15);
        set("race","人類");
        set("gender","男性");
        set("age",25);
        set("long","滄陵派入門已久的弟子，已經會一點入門的劍法跟基本的招喚術。\n");
        set_skill("dodge", 60);
        set_skill("sword", 50);
        set_skill("parry", 60);
        setup();
carry_object("/open/world1/acme/area/npc/wp/longsword")->wield();
add_money("coin", 1000);
}
