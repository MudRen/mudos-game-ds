//bag.c by luky
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD; //<--有用嗎?
void create()
{

set_name("旅行背包",({"travel bag","bag"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long",@LONG
一個可供旅行者存放雜物的袋子。(put 物 in bag 或是get 物 from bag)
LONG
);
        }
	set("value", 150);
	set("volume", 5);
	set_weight(1820);
	set("amount",1);
	set("usage","用來放置一些隨身攜帶的物品.");
	set_max_encumbrance(50000);
	set_max_capacity(100);
	setup();
}

int query_autoload() { return 1; }