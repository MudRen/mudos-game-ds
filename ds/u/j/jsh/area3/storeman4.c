#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�Ѥ�", ({ "old wang", "wang" }) );
        set("long",
                "�Z���u������A���X�Ӫ��Z���~��O�B�F���̫O�����C\n"
                        ); 
        set("chat_chance",10);
        set("chat_msg",({ 
"�Ѥ��j�n�ۥs:�U���Z���� ~ ~\n", 
"�Ѥ����ۤ⤤���K��V���ۿN�����K���A�ǳư��U�@�˪Z���F\n",
(: command,"come" :),
(: command,"say �o��ȤH�A�z�Q�n�I����..^^~" :),
}));
        set("sell_list",([
__DIR__"iron_sword": 5, 
__DIR__"iron_blade": 5, 
__DIR__"iron_dagger": 5,
__DIR__"iron_axe": 5,
__DIR__"iron_whip": 5,
__DIR__"iron_staff": 5, 
__DIR__"iron_fist": 5, 
__DIR__"iron_bow": 5,  
__DIR__"iron_pike": 5, 

]));
        set("level", 20);
        set("no_fight",1);
        set("age", 39);
        set("storeroom", __DIR__"/store4.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

