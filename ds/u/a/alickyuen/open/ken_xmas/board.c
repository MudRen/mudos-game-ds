
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"�����������s�~�S�O���ʡy���U�g���t�ϦѤH�z�R�߱Ʀ�]��"NOR, ({ "record" }) );
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
	if( !man ) return notify_fail("�Ч�u�W�Ův�p���C\n");

	write(man->report());
	return 1;
}
