#include <armor.h>
inherit NECK;
void create()
{
	set_name("小項鍊" ,({ "necklace" }) );
	set("long","一條長長的小項鍊，上面有一顆顆的小寶石。\n");
	set_weight(1100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "條" );
		set("value" , 1160);
		set("armor_prop/armor", 5);
		set("armor_prop/shield", 3);
		set("armor_prop/dodge", 3);
	}
	setup();
}
