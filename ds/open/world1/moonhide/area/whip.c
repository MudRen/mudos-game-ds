#include <ansi.h> 
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name(HIG"藤蔓條"NOR, ({ "ivy whip" , "whip" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",10);
                set("unit", "條");
                set("long", "這是一把道士專門施法用的劍。\n");
                set("value", 500);
        }
        init_whip(30);
        setup();
}

