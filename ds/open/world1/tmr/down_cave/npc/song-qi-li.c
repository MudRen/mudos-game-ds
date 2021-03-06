#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("宋淒厲", ({ "song qi-li" ,"song","li" }) );
        set("long",@long
    宋淒厲長得非常瘦弱，身上穿著的衣服好像只包著一塊木頭似的，
但他眼神異常，如不小心凝視過久，好像會被他控制住精神一樣。
long
);
        set_race("human");
        set("age", 30);
        set_stat_maximum("gin", 600);
        set_stat_maximum("hp", 600);
        set_attr("str",28);
        set_attr("cps",24);
        set_attr("cor",24);
        set_skill("blade",140 );
        set_skill("song blade" , 140 ); // 宋家刀法
        map_skill("blade","song blade");
        set_skill("parry",90);
        set_skill("dodge",90);
        set("attitude", "aggressive");
        set("title","硬幫幫中頭目");
        setup();
        set_level(20);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
          carry_object(__DIR__"obj/memory_card3");
}


