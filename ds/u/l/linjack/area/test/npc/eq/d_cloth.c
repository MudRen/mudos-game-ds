#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIC"���s�I�m"NOR, ({ "dragon cloth","cloth" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���A�W�������s��, ���L�s��Q������, ���äO�o�ܤj.\n");
		set("unit", "��");
		set("material", "cloth");
		set("limit_con",35);
		set("armor_prop/con",3);
		set("armor_prop/str",3);
		set("armor_prop/int",3);
		set("armor_prop/dex",3);
		set("armor_prop/hit",5);
		set("armor_prop/dodge",20);
		set("armor_prop/shield",10);
		set("armor_prop/armor", 20);
	}
	setup();
}
