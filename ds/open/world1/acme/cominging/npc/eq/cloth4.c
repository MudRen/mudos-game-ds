#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIR"�P"NOR"�ԳT" ,({ "fight cloth","cloth" }) );
	set("long","�@��Ѭӫҩҽ窺�ԳT�A�C�⹳�O���@��C\n");
	set_weight(1200);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
        set("material","silk");
		set("unit", "��" );
		set("value", 1100);
		set("armor_prop/armor", 7);
	}
	setup();
}
