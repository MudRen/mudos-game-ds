#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("�p�Y��", ({ "chieftain bandit","bandit"}) );
        set("long",@long
�@���y�W��ۤM�ͪ��g��p�Y�ءA������סA���c�������@�ۧA�ݡC
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
        set("title","�w����");
        setup();
		set_level(10);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/iron-armor")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
}

