#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�Z���ӤH" , ({ "weaponer" }) );
        set("level",10);
        set("race","�H��");
        set("age", 30);
        set("long","�A���e���k�l���b�d�i�e���ۡA�@�Ӹ��Y�鸣���k�l�A�A�i�H�V�L�R�Z���C\n");
set("sell_list", ([
__DIR__"wp/gun" : 1,
__DIR__"wp/clip" : 1,
]));
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_list","list");
}
