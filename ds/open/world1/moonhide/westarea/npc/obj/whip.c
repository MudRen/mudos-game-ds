#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("流君柔絲",({"liu whip","whip"}) );
        set("long","九天雲魂之流魂的武器，細如絲，幾乎看不到，殺傷力更佳。\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",3400);
        set("volume",5);
        set("material","iron");
        init_whip(34);
        }
        setup();
}

