#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("鯊骨", ({ "shark bone", "bone" }) );
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "段");
                set("long", "顧名思義, 就是鯊魚的骨頭.");
                }
        setup();
}
