#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�k����" , ({ "salesclerk" }) );
        set("level",10);
        set("race","�H��");
        set("age", 30);
set("gender","�k��");
        set("long","�@�Ӻ}�G���k�����b�ݩ��A�A�i�H�V�L�ʶR����C\n");
set("sell_list", ([
__DIR__"eq/mboots" : 1,
]));
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_list","list");
}
