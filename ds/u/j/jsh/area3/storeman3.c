#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("����"NOR, ({ "soup seller", "seller" }) );
        set("long",
                "������p�c�A�Ħ۵����s�W���ճD�N���C\n"
                        ); 
        set("chat_chance",10);
        set("chat_msg",({ 
(: command,"sweat" :),
(: command,"say �ܤF�o�ش��鶴��ܦn�� !" :), 
(: command,"say �ȩx..�Ӥ@�J�a!" :),}));
        set("sell_list",([
__DIR__"soup": 5,
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

