#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�����u����", ({ "beef noodle-boss", "boss" }) );
        set("long",
                "�������u������A�N�X�Ӫ������ѡA�s�a�կP���g�����f�C\n"
                        ); 
        set("chat_chance",10);
        set("chat_msg",({ 
"�������u����p���l�l������פ������� ~ ~\n",
(: command,"sweat" :),
(: command,"say �ӣ� ~ �ӣ� ~ �n�Y��������" :),
}));
        set("sell_list",([
__DIR__"noodle": 5,
]));
        set("level", 20);
        set("no_fight",1);
        set("age", 42);
        set("storeroom", __DIR__"/store2.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

