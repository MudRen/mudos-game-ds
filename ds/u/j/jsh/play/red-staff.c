#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIR"紅木之杖"NOR,({"red staff","staff"}));
set("long", 
"可憐老人所拿的拐杖，是一把紅色的木頭削成，看起來沒什麼特別的"

);
        set_weight(12000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "把");
            set("value",2000);
                set("volume",4);
          set("limit_str",24);
          set("limit_int",30);
        }
        set("weapon_prop/int",3);
init_staff(37);
        setup();
} 

