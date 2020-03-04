#include <armor.h>

inherit WAIST;

void create()
{
        set_name("荒野腰帶", ({ "field belt", "belt"}) );
        set_weight(300);

		if ( clonep() )
  			 set_default_object(__FILE__);
  		else {
                set("unit", "條");
                set("value", 1000);
                set("long", "這是一條流傳在血腥荒野上的腰帶，常被流浪在那邊的妖魔穿載著。\n");
                set("armor_prop", ([
                        "armor": 5,
                ]));
        }
        setup();
}

