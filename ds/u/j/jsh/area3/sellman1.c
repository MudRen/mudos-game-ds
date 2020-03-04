#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("���ĦѤH", ({ "pick medicine-man", "man" }) );
        set("long",
                "�@��H�s�Ӭ����ѤH�A�`�k�W�����s�h�Ķ��ħ��C\n"
                        ); 
        set("chat_chance",4);
        set("chat_msg",({ 
"���ĦѤH���n�۹D: �W���ħ��һs�Ӧ����ĤY�� ~ ~\n",
(: command,"sweat" :),(: command,"smile" :),
(: command,"say �ɦ� �ɮ� �ɯ� ���ĤY" :),(: command,"sigh" :),
}));
        set("sell_list",([
__DIR__"hp-pill": 10,
__DIR__"ap-pill": 10,
__DIR__"mp-pill": 10,
]));



        set("level", 20);
        set("no_fight",1);
        set("age", 60);
        set("storeroom", __DIR__"/store1.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

