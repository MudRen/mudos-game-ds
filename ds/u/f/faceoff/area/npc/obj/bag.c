//bag.c by luky
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
void create()
{

set_name("旅行背包",({"travel bag","bag"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long",HIG"一個可供旅行者存放雜物的袋子。(put 物 in bag 或是get 物 from bag)"NOR"\n");
        }
set("value", 50);
set_weight(1820);
set("amount",1);
set("usage","用來放置一些隨身攜帶的物品.");
set_max_encumbrance(10000);
this_object()->set_max_encumbrance(10000);
setup();
}

