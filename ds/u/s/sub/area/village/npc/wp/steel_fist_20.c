#include <weapon.h>
inherit FIST;
void create()
{
    set_name("鋼指虎",({"steel fist","fist"}));
    set_weight(6000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
                set("unit", "對");
                set("long",@LONG
這是一對用鋼製成的指虎，製作的相當精細。
LONG);
    }
        init_fist(20);
        setup();
        set("value",2100);
        set("volume", 4);
        set("limit_skill",30);
}

