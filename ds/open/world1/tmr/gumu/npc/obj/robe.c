#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("灰色道袍",({"gray robe","robe"}) );
        set("long",@long
這是一件灰色的道袍，為全真教的服飾。
long
);
        set_weight(1200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",2);
                set("unit", "件");
                 set("value",500);
                set("armor_prop/armor", 5);
        }
        setup();
}


