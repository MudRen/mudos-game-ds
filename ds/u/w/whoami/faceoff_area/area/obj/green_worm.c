#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("綠腹蟲", ({ "green worm","worm" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "隻");
                set("long", "一隻渾身碧綠的很詭異的小毛蟲, 沒什麼好敘述的.");
                }
        setup();
}
