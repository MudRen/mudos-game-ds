#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("���u" ,({ "long boots" }) );
	set("long","�@���������u�l�A���������b�b�C\n");
	set_weight(1100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��" );
		set("value" ,800);
		set("armor_prop/armor", 4);
	}
	setup();
}