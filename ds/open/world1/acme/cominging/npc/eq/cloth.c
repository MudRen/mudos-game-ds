#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("�x�A" ,({ "ossifer's cloth","cloth" }) );
	set("long","�o�O�󿤦ѷݥ��ɤW���®ɩҬ諸��A�C\n");
	set_weight(2500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
        set("material", "cloth");
		set("unit", "��" );
		set("value",800);
	}
	set("armor_prop/armor", 8);
	setup();
}
