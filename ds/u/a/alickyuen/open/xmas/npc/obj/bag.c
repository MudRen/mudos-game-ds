#include <ansi2.h>

inherit ITEM;

void create()
{
	set_name(HIR"�j�����U"NOR, ({ "big red bag", "bag", "xmas2001" }));

	set("long", @long
�@�Ӥj�����U�A�D�`��ΡA�O����ѤH���W���F��C
�A�i�H�γo�ӥ��U�h�B(load)���Y�����`�ѤH�C
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

	if( !str) return notify_fail("�A�n�Υ��U�h����F��?\n");

	if( str != "wood" ) return notify_fail("�o�ӥ��U�O����ѤH���A�h�B���Y�Ϊ��I\n");

	if( !objectp(wood = present("wood", environment(me)) ))
		return notify_fail("�o�̨S���o�˪F��C\n");

	if( wood->query_weight() < 10000 )
		return notify_fail("�o���줣�A�X�Ψӧ˳����C\n");

	message_vision(HIW"$N�p���l�l�a����Y�h�i���U��...\n"NOR, me);

	this_object()->add("time", 1);
	this_object()->add("heavy", wood->query_weight() );

	destruct(wood);

	me->start_busy(3);

	return 1;
}