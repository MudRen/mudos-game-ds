#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�񥬾c" ,({ "swathe shoe" , "shoe" , "swathe" }) );
	set("long","�o�O�@��Ҭ諸�c���A�i�N�㰦�}�]��C\n");
	set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��" );
		set("value" , 60);
		set("armor_prop/armor", 2);
		set("armor_prop/shield", 2);
		set("armor_prop/dodge", 1);
	}
	setup();
}
