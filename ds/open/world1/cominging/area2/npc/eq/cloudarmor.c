#include <armor.h>
inherit ARMOR;
void create()
{
	set_name("��m����",({"cloud armor","cloud","armor"}));
	set_weight(5500);            
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��`�`���쪺���ҡC\n");
		set("value",  200);
		set("armor_prop/armor",  2);  
	}
	setup();
}