#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"黑珍珠"NOR, ({ "pearl", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                     set("long", "一顆更高級的珍珠, 通常在當鋪都可以賣到極好的價錢.\n");
            set("value",4000);
                }
        setup();
}
