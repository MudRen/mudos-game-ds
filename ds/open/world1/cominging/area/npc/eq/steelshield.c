#include <armor.h>
inherit SHIELD;

void create()
{
	set_name("���K�@��",({"steel shield","shield"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("volume",4);
		set("long", "�o�O�@���`�����޵P�C\n");
		set("value",400);
	set("material","steel");
	}
	set("armor_prop/armor",3);
	setup();
}    

int query_autoload() { return 1;}
// save eq by alick
