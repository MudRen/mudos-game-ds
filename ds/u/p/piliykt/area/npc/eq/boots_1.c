#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("鐵靴", ({ "boots" }) );
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","這是一雙鐵靴子,重量非常重,但防禦很高.\n");
                set("unit", "雙");
                set("material","iron");
        set("value",2000);
                set("armor_prop/dex",-2);
                set("armor_prop/shield",1);
                set("armor_prop/armor", 16);
        }
        setup();
}

