#include <ansi.h>
#include <weapon.h>  
inherit AXE;
void create()
{
        set_name(WHT"�K��"NOR, ({ "iron axe" , "axe" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", "�@����Kű������C\n");
                set("value", 3000);
        }
        init_axe(50);
        setup();
}

