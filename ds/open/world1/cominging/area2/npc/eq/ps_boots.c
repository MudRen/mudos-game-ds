#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("�ֹu" ,({ "skin boots" , "boots" }) );
	set("long","�Υ֩Ұ������@���u�l�C\n");
	set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��" );
		set("value" , 260);
		set("armor_prop/armor", 3);
	}
	setup();
}
