#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("����H" , ({ "robot" }) );
        set("level",10);
        set("race","�����H");
        set("age", 30);
        set("long","�@�Ӿ���H�A���b���L�a�B�z��^���Ӫ��F��C\n");
        set("storeroom",__DIR__"item/shop1.c");
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}
