#include <npc.h>

inherit F_SOLDIER;

void create()
{
        set_name("�Ȧ�ĵ��", ({ "bank guard","guard" }) );
        set_race("human");
        set("age", 25);
        set_stat_maximum("gin",100);
        set_stat_maximum("hp",100);        
        set("long", "�@�ӧ��Ӫ��j�~�A�����ƪZ�ˡA�ԾԹ����ۦu�õۻȦ檺�w���C\n");
        setup();
        carry_object(__DIR__"obj/longsword")->wield();
          carry_object(__DIR__"obj/guard-armor")->wear();
          carry_object(__DIR__"obj/guard-cloth")->wear();
}

