#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIC"藤天面具"NOR,({ "turn-sky mask","mask" }) );
        set("long","八大迦裡的藤天迦，所裝的防具。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",3000);
                set("armor_prop/armor", 5);
        }
        setup();
}

