#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
        set_name(HIG"殺"HIW"君爪"NOR,({"sha fist","fist"}) );
        set("long","九天雲魂之殺魂的武器，由六隻鋼爪合併為一隻，殺氣蒸蒸不息。\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",3900);
        set("volume",5);
        set("material","iron");
        init_fist(39);
        }
        setup();
}

