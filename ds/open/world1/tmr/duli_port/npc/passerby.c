// man.c
#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("���H", ({ "passerby" }) );
        set_race("human");
        set("age", 25);
        set_stat_maximum("gin", 20);
        set_stat_maximum("hp", 20);
        set_attr("cps", 3);
        set("long", "�@�Ӵ��q���H�A�C�Ѧb��W���|�ݨ�Q�X�ӡC\n");
        setup();
        carry_money("coin", 50);
        carry_object(__DIR__"obj/longsword")->wield();
}

