#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�p���u�l" ,({ "heavy boots","boots" }) );
	set("long","�@���ݰ_�ӫܨI�����u�l�C\n");
	set_weight(3100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��" );
		set("value" , 900);
		set("armor_prop/armor", 6);
		set("armor_prop/shield", 4);
		set("armor_prop/dodge", -7);
	}
	setup();
}
