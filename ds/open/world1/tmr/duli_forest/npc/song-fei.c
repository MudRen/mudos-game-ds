#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("宋廢", ({ "song fei" ,"song","fei" }) );
        set("long",@long
　　宋廢是一個身材瘦高的中年男子，留著一頭披肩的長髮，臉上掛
著陰惻惻的笑容，瞧著你心裡發毛，只想快點遠離他。
long
);
        set_race("human");
        set("age", 40);
        set_stat_maximum("gin", 400);
        set_stat_maximum("hp", 400);
        set_attr("str",22);
        set_attr("cps",17);
                set_attr("cor",20);
                set_skill("axe",60);
                set_skill("parry",60);
                set_skill("dodge",60);
        set("attitude", "aggressive");
        set("title","硬幫幫小頭目");
        setup();
		set_level(15);
        do_heal();
        carry_object(__DIR__"obj/axe")->wield();
         carry_object(__DIR__"obj/yellow-cap")->wear();
           carry_object(__DIR__"obj/wolf-belt")->wear();
           carry_object(__DIR__"obj/portable-boots")->wear();
}



