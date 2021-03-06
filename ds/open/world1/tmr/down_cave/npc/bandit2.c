#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("小頭目", ({ "chieftain bandit","bandit"}) );
        set("long",@long
一個臉上橫著刀疤的土匪小頭目，滿身橫肉，正惡狠狠的瞧著你看。
long
);
        set_race("human");
        set("age", 35);
        set_stat_maximum("gin", 300);
        set_stat_maximum("hp", 300);
        set_attr("str",20);
        set_attr("cps",20);
        set_skill("blade",40);
        set_skill("parry",40);
        set_skill("dodge",40);
        set("attitude", "aggressive");
        set("title","硬幫幫");
        setup();
		set_level(10);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/iron-armor")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
}

