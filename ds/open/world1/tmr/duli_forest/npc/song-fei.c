#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("���o", ({ "song fei" ,"song","fei" }) );
        set("long",@long
�@�@���o�O�@�Ө����G�������~�k�l�A�d�ۤ@�Y�ܪӪ����v�A�y�W��
�۳��l�l�����e�A�@�ۧA�߸̵o��A�u�Q���I�����L�C
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
        set("title","�w�����p�Y��");
        setup();
		set_level(15);
        do_heal();
        carry_object(__DIR__"obj/axe")->wield();
         carry_object(__DIR__"obj/yellow-cap")->wear();
           carry_object(__DIR__"obj/wolf-belt")->wear();
           carry_object(__DIR__"obj/portable-boots")->wear();
}



