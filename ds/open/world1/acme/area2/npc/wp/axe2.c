#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
   set_name(HIR "鬼焚斧" NOR ,({"ghost fire axe","axe"}));
   set("long","這是一把火紅的大斧，看來並不輕。\n");
   set_weight(10000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",2500);
		set("volume",4);
                set("material","iron");
        }
                init_axe(35);
        setup();
}
