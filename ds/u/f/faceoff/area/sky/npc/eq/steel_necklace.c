#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIW"'鋼鍊"NOR, ({"steel necklace","necklace"}) );
        set("long", "一條純鋼打造的鋼鍊。\n");
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串" );
                set("armor_prop/armor", 5);
        set("material","steel");
                set("value", 1020);
        }
        setup();
}


