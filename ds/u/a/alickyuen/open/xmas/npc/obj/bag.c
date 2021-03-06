#include <ansi2.h>

inherit ITEM;

void create()
{
	set_name(HIR"大紅布袋"NOR, ({ "big red bag", "bag", "xmas2001" }));

	set("long", @long
一個大紅布袋，非常實用，是紅衣老人身上的東西。
你可以用這個布袋搬運(load)木頭給紅亡老人。
long);
	set("heavy", 0);
	set("time", 0);

	setup();
}

void init()
{
	add_action("do_load", "load");
}

int do_load(string str)
{
	object me, wood;
	
	me = this_player();

	if( !str) return notify_fail("你要用布袋搬什麼東西?\n");

	if( str != "wood" ) return notify_fail("這個布袋是紅衣老人給你搬運木頭用的！\n");

	if( !objectp(wood = present("wood", environment(me)) ))
		return notify_fail("這裡沒有這樣東西。\n");

	if( wood->query_weight() < 10000 )
		return notify_fail("這塊木不適合用來弄雪橇。\n");

	message_vision(HIW"$N小心翼翼地把木頭搬進布袋裡...\n"NOR, me);

	this_object()->add("time", 1);
	this_object()->add("heavy", wood->query_weight() );

	destruct(wood);

	me->start_busy(3);

	return 1;
}