#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"妖精糧食"NOR, ({ "elf cookie","cookie" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "妖精隨身所帶的乾糧，有強大的回復功\用。\n");
                set("unit", "片");
                set("value", 5000);  
                set("food_remaining",5);  // janshow
                set("heal_hp",300);   // jangshow
                set("heal_ap",300);   // jangshow
                set("heal_mp",300);   // jangshow
        }
}

