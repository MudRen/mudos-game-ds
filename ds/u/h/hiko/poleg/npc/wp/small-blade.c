#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("腰刀",({"blade"}) );
        set("long","一把可以繫在腰上的刀，多半是拿來護身用的。\n");
      set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
      set("value",1000);
                set("material","iron");
        }
                set("wield_msg","$N手上一晃，不知從何拿起了一把銳利的$n\n");
                init_blade(15);
                setup();
}

