#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("衛兵制服褲",({ "pant of guard","pant" }) );
        set("long","一件幽遮蘭城守衛所穿的制服褲。\n");
        set_weight(150);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",1);
         set("material","cloth");
                set("unit", "件" );
       set("value",30);
                set("armor_prop/armor", 3);
        }
        setup();
}

