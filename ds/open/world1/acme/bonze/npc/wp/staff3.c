#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("十方長杖",({"ten long staff","staff"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "這是一把相當長的杖，杖身呈士黃色，但在杖頭的地方卻泛紅。\n");
            set("value",2500);
       set("volume",3);
               set("material", "wood");
        }
        set("weapon_prop/str",1);
        set("weapon_prop/hit",5);
        set("limit_str",10);
        init_staff(36);
   setup();
}
