#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("衛兵制服",({ "uniform of guard","uniform" }) );
        set("long","一件紅藍相間的制服，穿上後一定很神氣！！\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",1);
         set("material","cloth");
                set("unit", "件" );
       set("value",30);
                set("armor_prop/armor", 2);
        }
        setup();
}

