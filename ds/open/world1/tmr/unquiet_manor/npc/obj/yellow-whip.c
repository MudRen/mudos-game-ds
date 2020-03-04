#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("黃骨鞭",({"yellow-bone whip","whip"}));
	set("long",@LONG
這是一條使用動物脊椎混雜著筋皮而製的骨鞭，整條骨鞭
通體都泛著月黃色，在月黑風高的夜裡看，更是黃中透著
血色，非常詭異。
LONG
	);
        set_weight(6000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "條");
            set("value", 1000);
			set("volume", 2);
            set("limit_str",30);
        }
		init_whip(45);
        setup();
} 

