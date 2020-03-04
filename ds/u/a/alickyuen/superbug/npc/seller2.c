#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("機械人" , ({ "robot" }) );
        set("level",10);
        set("race","機器人");
        set("age", 30);
        set("long","一個機械人，正在忙碌地處理剛回收來的東西。\n");
        set("storeroom",__DIR__"item/shop1.c");
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}
