#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("纏布鞋" ,({ "swathe shoe" , "shoe" , "swathe" }) );
	set("long","這是一般所穿的鞋類，可將整隻腳包住。\n");
	set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙" );
		set("value" , 60);
		set("armor_prop/armor", 2);
		set("armor_prop/shield", 2);
		set("armor_prop/dodge", 1);
	}
	setup();
}
