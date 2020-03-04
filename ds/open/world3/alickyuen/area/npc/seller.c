#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name(YEL"回收機械人"NOR , ({ "robot" }) );
        set("level",10);
        set("race","機器人");
        set("age", 30);
         set("no_fight",1);
        set("long","這個機械人是負責回收的工作。\n");
        set("chat_chance",8);
        set("chat_msg",({
           "在旁的喇叭突然響起:回收各式各樣的產品！\n",
           "機械人說道:歡迎,歡迎~\n",
        }) );
        set("storeroom",__DIR__"item/shop1.c");
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}
