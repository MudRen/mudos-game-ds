#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIY"閃雷石之鍊"NOR, ({"thunder necklace","necklace","thunder" }) );
        set("long", "一條形似雷電的寶石項鍊。\n");
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串" );
                set("armor_prop/armor",  3);
                set("armor_prop/dex", 3);
                set("value", 10000);
        }
        setup();
}
