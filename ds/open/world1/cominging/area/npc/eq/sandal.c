#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("草鞋", ({ "sandal", "草鞋" }) );
	set("long","這是在一般地方都見的到的一種腳部防具。\n");
	set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙");
	set("material","plant");
		set("value" , 220);
		set("armor_prop/armor", 2);
		set("armor_prop/shield", 1);
	}
	setup();
}
