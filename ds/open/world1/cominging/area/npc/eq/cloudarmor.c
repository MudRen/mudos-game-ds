#include <armor.h>
inherit ARMOR;
void create()
{
	set_name("��m����",({"green armor","armor"}));
	set_weight(5500);            
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
	set("material","leather");
		set("long", "�o�O�@��`�`���쪺���ҡC\n");
		set("value",  200);
		set("volume",4);
		set("armor_prop/armor",  2);  
	}
	setup();
}
int query_autoload() { return 1;}
// save eq by alick
