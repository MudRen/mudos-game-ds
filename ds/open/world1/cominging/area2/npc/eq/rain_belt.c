#include <armor.h>
inherit WAIST;

void create()
{
	set_name("�m�i�y�a" ,({ "rainbow belt" , "belt" }) );
	set("long","�@���ݰ_���C��Q���A�v���y�a�A���O�@���m�i�@��C\n");
	set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��" );
		set("value" , 500);
		set("armor_prop/armor", 5);
	}
	setup();
}
