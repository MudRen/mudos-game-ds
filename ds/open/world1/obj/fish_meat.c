#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("魚肉", ({ "meat", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "塊");
                set("long", "一塊生腥的魚肉, 這樣是沒辦法食用的.");
                }
        setup();
}