#include <ansi.h>
#include <weapon.h>  
inherit FORK; 
void create()
{
        set_name(WHT"鐵槍"NOR, ({ "iron pike" , "pike" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", "一把用鐵鑄成的槍。\n");
                set("value", 3000);
        }
        init_fork(50);
        setup();
}

