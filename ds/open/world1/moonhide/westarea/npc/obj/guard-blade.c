#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("逐日者之刀",({"sun-follow blade","blade"}) );
        set("long","逐日者之刀是把銀白色的大刀，握柄處是像雲朵一樣的不知名材質。\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",2000);
        set("volume",5);
        set("material","iron");
        init_blade(42);
        }
        setup();
}


