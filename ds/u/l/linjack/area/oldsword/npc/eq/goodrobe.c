#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("�A�T", ({ "robe" }) );
	set_weight(4500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","��������e��, �Ӧ���ƤQ������, ���ӬO�����H�a�b�諸��A,\n"
			   "���L�@�u�@�I, �o�T���S�f�O����, �����D�]�󦳳o�˩Ǫ��]�p?\n");
		set("unit", "��");
		set("material", "cloth");
		set("value",1000);
	}
	set("armor_prop/shield",2);
	set("armor_prop/armor", 5);
	setup();
}
