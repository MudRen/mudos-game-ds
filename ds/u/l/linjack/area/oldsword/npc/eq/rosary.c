#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name("��]", ({ "rosary" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@�����̤l�Φ�Ю{�|�رa����].\n");
		set("unit", "��");
		set("value",300);
		set("material","wood");
	}
	set("armor_prop/armor",1);
	set("armor_prop/int",2);
	set("armor_prop/show_damage",1);
	setup();
}
