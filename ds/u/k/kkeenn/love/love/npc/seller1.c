#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name(HIC"朝奉"NOR , ({ "seller" }) );
        set("level",1);
        set("gender","女性");
        set("age", 30);
         set("no_kill",1);
        set("long","專門收購你們不要的東西的偉大女性(sell)。\n");
        set("storeroom",__DIR__"room31.c");
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}

