#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(HIC"���s�I�u"NOR, ({ "dragon boots","boots" }) );
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���u�l�W�������s��, ���L�s��Q������, ���äO�o�ܤj.\n");
		set("unit", "��");
		set("material", "cloth");
		set("limit_dex",30);
	}
	set("armor_prop/con",3);
	set("armor_prop/str",3);
	set("armor_prop/int",3);
	set("armor_prop/dex",3);
	set("armor_prop/hit",3);
	set("armor_prop/dodge",15);
	set("armor_prop/shield",3);
	set("armor_prop/armor", 8);
	setup();
}
