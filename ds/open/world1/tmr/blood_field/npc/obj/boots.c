#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("荒野長靴", ({"field boots", "boots" }) );
        set_weight(1500);

		if ( clonep() )
  			 set_default_object(__FILE__);
		else {
                set("unit", "雙");
                set("value", 1500);
                set("long",@long
這是一雙流傳在血腥荒野上的長靴，常被流浪在那邊的妖魔穿載著。
long
                );
                set("armor_prop", ([
                        "armor": 5,
                ]));
        }

        setup();
}

