#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(HIY"重厚皮靴" NOR, ({ "big boots", "boots" }) );
	set("long","這是一般軍士所穿的鞋子,具有很好的防禦力\n");
	set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth" );
		set("unit", "雙" );
		set("value" , 130);
		set("armor_prop/armor", 4);
		set("armor_prop/shield", 5);
	}
	setup();
}
