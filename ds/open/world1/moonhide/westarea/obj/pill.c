/*	File : "/open/world1/moonhdie/westarea/obj/pill.c"		*
 *	Author : Alickyuen@DS on 12/2001			*/

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

int random_case();
int poison();
int unconcious();

void create()
{
	set_name(HIW"�����٦X��"NOR, ({ "six around pill","pill" }) );
	set_weight(50);
	set("long", @long
�o�@�ɬO�E�ѥȤk���ѤU����ءA�ƭP�Ӧ����P�ġA�ڻ��@�����إ\
�ΡA���S�H���D��u���\�ġA�B���C���Y�ɪ��\�ĳ����P�A�Y�n�զY
�A�Х����n�߲z�ǳơI
long);
	set("unit","��");
	set("value", 10);      	
	set("food_remaining",1);
	set("changed", 0);

	setup();
}

void init()
{
	:: init();

	if( !this_object()->query("changed") )	random_case();
}

int random_case()
{
	this_object()->set("changed", 1);

	switch(random(6))
	{
		case 0:
			this_object()->set("heal_hp", 1000);
			return 1;
		break;
		case 1:
			this_object()->set("heal_ap", 1000);
			return 1;
		break;
		case 2:
			this_object()->set("heal_mp", 1000);
			return 1;
		break;
		case 3:
			this_object()->set("heal_hp", 1000);
			this_object()->set("heal_mp", 1000);
			this_object()->set("heal_ap", 1000);
			return 1;
		break;
		case 4:
			this_object()->set("heal_hp", 1);
			this_object()->set("food/function", (: poison :));
			return 1;
		break;
		case 5:
			this_object()->set("heal_hp", 500);
			this_object()->set("heal_mp", 500);
			this_object()->set("heal_ap", 500);
			return 1;
		break;
		default:
			return 1;
		break;
	}
}
	

int poison()
{
	object me = this_player();

	message_vision(HIR"$N��M�����ܶ¡A���O���r�F�I\n"NOR, me);

	me->apply_condition("poison", me->query_condition("poison")+ (me->query("level")+random(me->query("level"))) );

	return 1;
}

int unconcious()
{
	object me = this_player();

	message_vision(HIR"$N��M����@�ܡA�N���˦b�a�W�F......\n"NOR, me);

	me->unconcious();

	return 1;
}
