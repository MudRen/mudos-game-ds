#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("宋連", ({ "song lian" ,"song","lian" }) );
        set("long",@long
　　宋連身材頗高，但挺著一個啤酒肚，一眼望就像是個酒色過度的
中年男人。但他將硬幫幫中的鎮幫武技「宋家刀法」搭配自已的一套
步法，使用起來倒還頗具威力。
long
);
        set_race("human");
        set("age", 40);
        set_stat_maximum("gin", 600);
        set_stat_maximum("hp", 600);
        set_attr("str",28);
        set_attr("cps",24);
        set_attr("cor",24);
        set_skill("blade",120 );
        set_skill("song blade" , 120 ); // 宋家刀法
        map_skill("blade","song blade");
        set_skill("parry",80);
        set_skill("dodge",80);
        set("attitude", "aggressive");
        set("title","硬幫幫中頭目");
        setup();
        set_level(20);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
          carry_object(__DIR__"obj/memory_card1");
}

