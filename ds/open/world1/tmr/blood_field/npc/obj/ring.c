#include <armor.h>

inherit FINGER;

void create()
{
	set_name("荒野戒指", ({ "field ring" }) );
	set_weight(100);
	set("unit", "枚");
	set("value", 1500);
	set("long",@long
這是一枚流傳在血腥荒野上的戒指，常被流浪在那邊的妖魔穿載著，通
常擁有奇特的魔力。                
long
                );
		if ( clonep() )
  			 set_default_object(__FILE__);
		else {
                set("armor_prop", ([
                        "armor": 5,
                    	"int": 1,
                ]));
        }
        setup();
}

