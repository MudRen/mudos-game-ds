#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("巡邏者", ({ "garrison bandit","bandit"}) );
        set("long",@long
一個硬幫幫中的土匪巡邏者，武藝明顯比一些小角色高多了。
long
);
        set_race("human");
        set("age", 35);
        set_stat_maximum("gin", 400);
        set_stat_maximum("hp", 500);
        set_attr("str",20);
        set_attr("cps",20);
        set_skill("blade",80);
        set_skill("parry",60);
        set_skill("dodge",60);
        set("attitude", "aggressive");
        set("title","硬幫幫");
        setup();
        set_level(15);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
          carry_object(__DIR__"obj/shortsword")->wield("secondhand sword");

        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/iron-armor")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
}


