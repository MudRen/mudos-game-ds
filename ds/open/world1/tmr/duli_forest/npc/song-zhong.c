#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("宋終", ({ "song zhong" ,"song","zhong" }) );
        set("long",@long
　　宋終是一個滿臉橫肉的壯碩大漢，二個眼睛一個大一個小，兩耳
招風，頂著有點肥大的肚子，但是從他兩臂上發達的肌肉和厚實的胸
膛看來，倒也不敢讓人小覷他。
long
);
        set_race("human");
        set("age", 40);
        set_stat_maximum("gin", 400);
        set_stat_maximum("hp", 400);
        set_attr("str",24);
        set_attr("cps",17);
                set_attr("cor",22);
                set_skill("blade",60);
                set_skill("parry",60);
                set_skill("dodge",60);
        set("attitude", "aggressive");
        set("title","硬幫幫小頭目");
        setup();
		set_level(15);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
         carry_object(__DIR__"obj/yellow-cap")->wear();
           carry_object(__DIR__"obj/portable-boots")->wear();
}



