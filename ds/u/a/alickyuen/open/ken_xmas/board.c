
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"☆２００２新年特別活動『幫助迷路聖誕老人』愛心排行榜☆"NOR, ({ "record" }) );
	set("long", "");
	set("no_get", 1);
	set("no_sac", 1);

	setup();
}
void init()
{
	add_action("do_look", "look");
}

int do_look(string id)
{
	object man;
	man = find_living("ken_xmas");
        if( id != this_object()->query("id") ) return 0; 
	if( !man ) return notify_fail("請找線上巫師聯絡。\n");

	write(man->report());
	return 1;
}
