#include <armor.h>

inherit BOOTS;void create()
{
        set_name("重靴",({"heavy boots","boots"}) );
        set("long","這是一雙厚重的靴子，十分的保暖。");
        set_weight(4000);
  if ( clonep() )
    set_default_object(__FILE__);
        else
        {
                set("volume",1);
                set("unit","雙");
                set("value",3000);
                set("armor_prop/armor",12);
        }
        setup();
}

