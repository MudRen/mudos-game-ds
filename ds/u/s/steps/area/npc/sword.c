#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name(CYN"�ۼC"NOR, ({ "sword" }) );
        set("gender", "�k��" );
        set("level",15);
        set("age", 15);
        set("long",
                "�L�O�J�|�����Ӥl�A���ɭԷ|�ӳJ�|������\n"
        );
        set("chat_chance", 4);
        set("chat_msg", ({
                "�ۼC�V�Ѥj�ۡG�ڭn�V�O�I�ڭn�[�o�I\n",
                "�ۼC���ۻ��G�ڭ̳o�a�J�|���@�w�|�o�����j�I\n",
                "�ۼC�������e�����G�o��ȤH�A�ڭ̪����O�A�s�J�|�A�аݦ�����ݭn�ܡH\n",
        }));
        set("sell_list",([      
                 __DIR__"cake/mangocake"        : 20, 
                 __DIR__"cake/chocolatecake"        : 25, 
                 __DIR__"cake/berrycake"        : 23, 
        ]));
            setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
