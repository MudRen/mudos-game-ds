#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_drink", "drink");
}


void create()
{
	set_name(HIW "�ŹT" NOR, ({"cheese"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�@�J�������A���T�A����(drink)���T�N����ӹL�j���C\n");
		set("unit", "�J");
		set("value", 2000);
	}
}

int do_drink(string arg)
{	
	object me = this_player();
	if (!living(me)) return notify_fail("�Q����ܡH\n");
	if (!id(arg)) return 0;

	message_vision(HIG "$N���L���L�a�ܧ��@�J" + this_object()->query("name")+ HIG "�C\n"NOR,me);
    me->receive_heal("ap", 100);
  	destruct(this_object());  
  	
  	return 1;     
}

