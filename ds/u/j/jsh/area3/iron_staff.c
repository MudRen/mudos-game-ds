#include <ansi.h>
#include <weapon.h>  
inherit STAFF; 
void create()
{
        set_name(WHT"鐵手杖"NOR, ({ "iron staff" , "staff" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", "一把用鐵鑄成的手杖。\n");
                set("value", 3000);
        }
        init_staff(50);
        setup();
}

