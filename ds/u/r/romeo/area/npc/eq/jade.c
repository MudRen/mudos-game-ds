#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name("烏金斷玉" ,({ "black-gold-jade","jade" }) );
        set_weight(900);
        set("long","這是一隻斷裂的手鐲，當年這隻手鐲是從東瀛漂流過來的
，有著非凡的意義。\n");
        if ( clonep() )
              set_default_object(__FILE__);
        else {
         set("material","jade");
                set("unit", "個" );
                set("value",1000);
        }
        set("armor_prop/armor", 1);
        set("armor_prop/shield", 2);
        setup();
}

