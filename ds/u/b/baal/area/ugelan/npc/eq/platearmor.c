#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("鎧甲",({ "plate armor","armor" }) );
        set("long","一件以鐵打造而成的鎧甲，是戰士們愛用的戰場裝備。\n");
        set_weight(20500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
        set("material", "iron");
                set("unit", "件" );
       set("value",2000);
                set("armor_prop/armor", 30);
                        set_temp("apply/armor",7);

        }
        setup();
}

