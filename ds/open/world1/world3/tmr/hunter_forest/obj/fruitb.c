#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("果實肉",({"pulp"}) );
        set_weight(200);
        set("long",@long
一坨鮮白的果肉，散發地一股濃厚香醇的酒香味。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else {
        set("value",1);
        set("material","plant");
        set("volume",1);
	}
        setup();
}