#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name(HIG"破"HIW"君斧"NOR,({"poo axe","axe"}) );
        set("long","九天雲魂之破魂的武器，由精石鑄造而成，堅硬無比。\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",3800);
        set("volume",5);
        set("material","iron");
        init_axe(38);
        }
        setup();
}

