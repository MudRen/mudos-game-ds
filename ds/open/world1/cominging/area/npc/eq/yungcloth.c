#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIM"�m��"HIG"��"NOR, ({ "yung cloth", "cloth" }) );
	set("long", "�ǻ����o���A�O�����s�W�P�H�Ҭ諸�P�T�C\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��" );
		set("armor_prop/str",    1);
	set("material","cloth");
		set("armor_prop/armor",  15);
		set("value",7000);
	}
	setup();
}
