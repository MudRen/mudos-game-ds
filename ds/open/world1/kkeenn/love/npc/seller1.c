#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name(HIC"�©^"NOR , ({ "seller" }) );
        set("level",1);
        set("gender","�k��");
        set("age", 30);
         set("no_kill",1);
        set("long","�M�����ʧA�̤��n���F�誺���j�k��(sell)�C\n");
        set("storeroom",__DIR__"room31.c");
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}

