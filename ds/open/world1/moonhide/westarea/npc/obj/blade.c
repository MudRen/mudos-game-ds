#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("夢君刀",({"mon blade","blade"}) );
        set("long","九天雲魂之夢魂的武器，刀頭還插著一把小刀，頓時加長了五寸。\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",3700);
        set("volume",5);
        set("material","iron");
        init_blade(37);
        }
        setup();
}

