#include <ansi2.h>

inherit ITEM;

void create()
{
	set_name(YEL"�쳷��"NOR, ({ "wooden sledge", "sledge" }));

	set("long", @long
�@�ӥѤ��Y��s�Ӧ����쳷���C
long);
	set("ridable",1);
	set("value", 1);
	set("speed", 0);

	setup();
}

int ride_before_action(object me)
{
	object ob=this_object();

	message_vision("$N�@���N���W�F"+this_object()->name()+"�C\n",me);

	return 1;
}

int ride_after_action(object me)
{	
	message_vision("$Níí�����b"+this_object()->name()+"���W���F�C\n",me);
	
	return 1;
}

int ride_off_action(object me)
{
	message_vision("$N�q"+this_object()->name()+"�����F�U�ӡC\n",me);

	return 1;
}