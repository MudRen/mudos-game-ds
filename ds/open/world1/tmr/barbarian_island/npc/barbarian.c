#include "barbarian_base.c"
inherit NPC;

void create()
{
        set_name("野蠻人", ({ "barbarian" }) );
        set("long",@long
一個赤裸著上半身，而下半身穿著件獸皮似的毛褲，瞧起來就是過著茹毛飲血的日子
，長的一副暴力而血腥的模樣，而他似乎也正懷好意的打量你？
long
);
        set("age", 25);
        setup();
        carry_object("/d/obj/woodblunt")->wield();
	carry_object(__DIR__"obj/monster_pants")->wear();

}

