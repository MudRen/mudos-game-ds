#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit ARMOR;
void create()
{
	set_name(CYN"�C����"NOR, ({ "cloud armor","armor" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���Z�ҽ�a���Ӱ��, �ӥB���ʤO��, ²���M��A�S���,\n"
                           "���O���m�O�o�W�G�@��H���Q��.\n");
		set("unit", "��");
		set("value",20000);
		set("material","steel");
		set("limit_con",15);
		set("limit_int",10);
	}
	set("armor_prop/con",-2);
	set("armor_prop/str",-1);
	set("armor_prop/int",1);
	set("armor_prop/dex",2);
	set("armor_prop/dodge",10);
	set("armor_prop/shield",25);
	set("armor_prop/armor", 30);
	setup();
}
