// Room: /d/gumu/obj/huju-jia.c
// Last Modifyed by Winder on Jan. 14 2002
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW "�@��[" NOR, ({ "huju jia", "jia" }) );	 
	set_weight(30000000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "�@�Ӥ��Y����[�l�A�W�������K��(armor)���@��C�A�i�H��(na)�ǥh�ΡC\n");
		set("material","wood");
		set("no_get",1);
	}
	set("count", 4);
	setup();
}

