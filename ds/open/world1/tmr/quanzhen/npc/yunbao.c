// yunbao.c ���\

#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("���\\", ({ "yun bao", "bao" }) );
     set("race", "���~");
        set("gender", "�۩�");
        set("age", 5);
        set("long", @LONG
�o�O�@�u�㸭��֪����\�A������ַ��������B�p��C
LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("combat_exp", 30000);
        set("neili",800);
        set("jiali",100);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 1000);

        setup();
}

