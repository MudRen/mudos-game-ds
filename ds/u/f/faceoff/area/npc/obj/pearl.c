#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"珍珠"NOR, ({ "pearl", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long", "一顆高級珍珠, 通常在當鋪都可以賣到不錯的價錢.\n");
            set("value",6000);
                }
        setup();
}