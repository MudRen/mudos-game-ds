#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIC"�������Z"NOR, ({ "full armor","armor" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���Z�Ҳ��`���­��A���M�Q���A�X�Φb�x�ƾԳ��W��, ��\n"
                           "�]���ӹL�­�, �O�S�H��o�ؾԥҨӦ樫�������.\n");
		set("unit", "��");
		set("value",9999);
		set("material","steel");
		set("limit_con",40);
		set("limit_int",10);
	}
	set("armor_prop/dex",-5);
	set("armor_prop/dodge",-30);
	set("armor_prop/shield",5);
	set("armor_prop/armor", 38);
	setup();
}
