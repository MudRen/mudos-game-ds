#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIY"英雄之斧"NOR,({"hero axe","axe"}) );
        set("long","暫時用這個名字...\n");
        set_weight(16000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","把");
        set("volume",2);
        set("value",1000);
        }
        init_axe(30);
        setup();        
}

