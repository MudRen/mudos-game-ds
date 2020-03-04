#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLK"�¯�"NOR, ({ "black grass", "grass" }) );
	set("long", "�¦⪺��A�������ƻ�@�ΡC\n");
        set_weight(500);
	set("value", 10);
	set("unit", "��");
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if( arg == "black grass" || arg == "grass" ) 
	{
		message_vision("$N�Y�U�@��"+this_object()->query("name")+"�C\n"NOR, me);
                me->apply_condition("scolopendra_poison", me->query_condition("scolopendra_poison")-random(10));
		if( me->query_condition("scolopendra_poison") < 0 ) me->apply_condition("scolopendra_poison", 0);
		tell_object(me, YEL"�A�P���餺�����G�r���Ҵ�w�C\n"NOR);
	}
	destruct(this_object());
	return 1;
}
