#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("耳環", ({ "earring" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long", "虞妙如的耳環!!");
                }
        setup();
}

