#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("鯉魚肉", ({ "meat", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "塊");
                set("long", "一塊高級魚肉,不過生的是無法食用的.");
                }
        setup();
}