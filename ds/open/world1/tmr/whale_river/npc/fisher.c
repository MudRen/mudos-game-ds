// fisher.c ����

#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("����", ({"fisher" }) );
        set_race("human");
        set("age", 40);
        set_stat_maximum("gin", 20);
        set_stat_maximum("hp", 20);
        set("long", "�@�����ۤ���A���b���������ȡC\n");
        set("chat_chance", 8);
        set("chat_msg", ({
                "���ȯ��_�ӱ�F��򭱡A���ۻy�D�G�u����������Ƿ|���|�A�{��...�v\n",
                "���Ȧ������F���Y�W����...\n",
                "������L�Y�ӱ�F�A�@���A�S��^�h�~�򧤵۳����C\n",
        }) );

        setup();
        carry_money("coin", 10);
        carry_object(__DIR__"obj/rod")->wield();
        carry_object(__DIR__"obj/hat")->wear();
}

