#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name("凌君槍",({"lin pike","pike"}) );
        set("long","九天雲魂之凌魂的武器，整枝發出淡淡綠光，好不尋常。\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",4000);
        set("volume",5);
        set("material","iron");
        init_fork(40);
        }
        setup();
}

