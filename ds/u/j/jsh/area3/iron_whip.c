#include <ansi.h>
#include <weapon.h>  
inherit WHIP; 
void create()
{
        set_name(WHT"鐵鞭"NOR, ({ "iron whip" , "whip" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "條");
                set("long", "一條用鐵鑄成的鞭子。\n");
                set("value", 3000);
        }
        init_whip(50);
        setup();
}

