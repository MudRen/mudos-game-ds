#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("���ު�", ({ "garrison bandit","bandit"}) );
        set("long",@long
�@�ӵw���������g�ꨵ�ު̡A�Z�������@�Ǥp���Ⱚ�h�F�C
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
        set("title","�w����");
        setup();
        set_level(15);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
          carry_object(__DIR__"obj/shortsword")->wield("secondhand sword");

        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/iron-armor")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
}


