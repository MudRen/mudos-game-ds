#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
     set_name( YEL"���Z�H"NOR"��"HIW"��q����"NOR,({"barbarian hammer","hammer"}) );
     set_weight(12000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("unit", "��");             
            set("value",13000);
            set("material","gold"); 
           }         
        set("limit_str",40);
        set("limit_level",25);
        init_hammer(70);
        setup();
}
