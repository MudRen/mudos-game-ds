#include <ansi.h>
#include <weapon.h>  
inherit STAFF; 
void create()
{
        set_name(WHT"�K���"NOR, ({ "iron staff" , "staff" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", "�@����Kű��������C\n");
                set("value", 3000);
        }
        init_staff(50);
        setup();
}

