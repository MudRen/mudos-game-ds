#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_drink", "drink");
}


void create()
{
	set_name(HIW "乳酪" NOR, ({"cheese"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗香甜的鮮奶酪，不喝(drink)奶酪就不算來過大草原。\n");
		set("unit", "碗");
		set("value", 2000);
	}
}

int do_drink(string arg)
{	
	object me = this_player();
	if (!living(me)) return notify_fail("想當機嗎？\n");
	if (!id(arg)) return 0;

	message_vision(HIG "$N骨碌骨碌地喝完一碗" + this_object()->query("name")+ HIG "。\n"NOR,me);
    me->receive_heal("ap", 100);
  	destruct(this_object());  
  	
  	return 1;     
}

