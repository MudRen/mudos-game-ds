#include <armor.h>

inherit PANTS;

void create()
{
        set_name("洞洞褲",({"holes pants","pants"}) );
        set("long","一件由高級布料織成，看來滿耐穿的。\n");
        set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",3);
                set("unit","件");
                set("value",1000);
          set("armor_prop/armor",10);
        }
        setup();
}

