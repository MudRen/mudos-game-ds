#include <armor.h>
inherit LEGGING;
void create()
{
	set_name("���ê��H��" ,({ "rusty leggings","leggings" }) );
	set("long","�o�u�O�@�����ê��H�ҡC\n");
	set_weight(2000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
	set("material", "leather");
	set("volume",5);
	set("unit", "��");
	set("value",100);
	}
	set("armor_prop/armor",1);
	setup();
}
