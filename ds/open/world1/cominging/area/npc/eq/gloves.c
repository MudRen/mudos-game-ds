#include <armor.h>
inherit HANDS;

void create()
{
	set_name("���M��" ,({ "cloth gloves","gloves" }));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@���Υ��_������M, �٥i�H�O�Ƿx�C\n");
		set("value", 125);
		set("armor_prop/armor", 2);
		set("armor_prop/shield",1);
	set("material","cloth");
	}
	setup();
}    
int query_autoload() { return 1;}
// save eq by alick
