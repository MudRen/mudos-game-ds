#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;
inherit F_VENDOR;

int pill_total=10;
void do_eat_pill()
{
        object ob=this_object();
        if(ob->is_busy()) return;
        if(pill_total==0) return;
        if(ob->query_stat("hp")<ob->query_stat_maximum("hp") ) {
                message_vision(HIG"$N迅速地從懷中拿了顆藥丸吞了下去...\n"NOR,ob);
                pill_total--;

                do_heal();
        }
}
void create()
{
    set_name("步青山", ({ "bu qing shan","bu","shan"}) );

    set_race("human");
    set_skill("parry", 50);
    set_skill("unarmed", 50);
    set_skill("dodge", 50);
    set_skill("whip",80);

    set("title","小館醫生");
    set("age",30);
    set("long",@long
步青山是這漁村土生土長的醫生，也是唯一的一位醫生，個性良善好
施，每當村民有大小病痛時，他總是第一個趕緊救治，非常受大家的愛載
，要是你受了什麼傷，倒不妨可以給他醫治。
long
);
    set("chat_chance", 5);
    set("chat_msg", ({
        "步青山正伸著手搭著一個村民的脈膊上，正凝神診聽中......\n",
        "步青山從後堂藥櫃中拿出了幾味藥，交待了來看病的村民幾句...\n",
        "步青山望了你一眼，又轉回去做他自已的事了。\n",
   }));
        set("merchandise", ([
                "/d/obj/drug/fengwei-herb": 30,
        ]));
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: do_eat_pill :),      // 戰鬥中吃藥補血..
    }));

    setup();
    set_level(15);
          carry_object(__DIR__"obj/large-fengwei-herb");
        carry_object(__DIR__"obj/white-jade-ring")->wear();
          carry_object("/d/obj/shortwhip")->wield();

}
void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}


int accept_fight(object ob)
{
        return 1;
}


