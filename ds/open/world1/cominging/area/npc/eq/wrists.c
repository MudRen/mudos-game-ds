#include <armor.h>
inherit WRISTS;
void create()
{
	set_name("���@��",({"wrists"}));
	set_weight(2100);            
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��ܥ��`���@�áC\n");
		set("value", 200);
		set("armor_prop/armor", 2);  
	set("material","cloth");
	}
	setup();
}
int query_autoload() { return 1;}
// save eq by alick
