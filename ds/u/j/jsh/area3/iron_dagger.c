#include <ansi.h>
#include <weapon.h>  
inherit DAGGER; 
void create()
{
        set_name(WHT"�K�P��"NOR, ({ "iron dagger" , "dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", "�@����Kű�����P���C\n");
                set("value", 3000);
        }
        init_dagger(50);
        setup();
}

