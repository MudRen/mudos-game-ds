#include <armor.h>
inherit WAIST;

void create()
{
	set_name("�x�θy�a" ,({ "waist" }) );
	set("long","�@���x�H�Ϊ��y�a�A�W���i�H���ǪF��C\n");
	set_weight(700);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��" );
		set("value" , 1000);
		set("armor_prop/armor", 6);
		set("armor_prop/shield", 2);
	}
	setup();
}
