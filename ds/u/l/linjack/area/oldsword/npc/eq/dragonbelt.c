#include <armor.h>
#include <ansi.h>
inherit WAIST;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"���s�y�a"NOR, ({ "dragon belt","belt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O���æ��@�����s���ָy�a, ���������򯫩_���\��.\n");
		set("unit", "��");
		set("value",12000);
		set("material", "cloth");
		set("replica_ob",__DIR__"belt.c");
	}
	set("armor_prop/armor", 3);
	set("armor_prop/shield",30);
	setup();
}
