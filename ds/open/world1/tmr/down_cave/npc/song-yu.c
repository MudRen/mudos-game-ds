#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
        set_name("����", ({ "song yu" ,"song","yu" }) );
        set("long",@long
�@�@���ɬO�w�������ߤ@���k�ʡA���O���Ⱚ�j�A���k�⧺�a�M�k�w
�F�X���޵ѡA�[�W�ͩʥ����A���M�������D�A�e������A���O������
��������o�O���q�����N�C
long
);
        set_race("operation");

        set("age", 35);
        set("force_ratio",10);
        set_attr("operation" , 60);
        set("gender","female");
        set_skill("parry" , 80);
        set_skill("psychical" , 100);
        set_skill("blade" , 100);
        set_skill("secondhand blade" , 100);
        set_skill("song blade" , 120);
        map_skill("blade","song blade");
        map_skill("secondhand blade","song blade");
        set_skill("dodge" , 80);
        set("attitude", "aggressive");
        set("title","�w�����G����");
        setup();
        set_level(30);
        set_attr("int",18);
        set_attr("cps",18);
        carry_object(__DIR__"obj/cyan-hairpin")->wear();
        carry_object(__DIR__"obj/song-blade-book");
        carry_object(__DIR__"obj/right-lao-blade")->wield();
        carry_object(__DIR__"obj/left-sui-blade")->wield();
}

