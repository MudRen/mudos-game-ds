#include <ansi.h>
#include <weapon.h>  
inherit FIST; 
void create()
{
        set_name(WHT"�K��"NOR, ({ "iron fist" , "fist" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", "�@����Kű�������C\n");
                set("value", 3000);
        }
        init_fist(50);
        setup();
}

