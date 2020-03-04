#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(HIR"紅色巨齒"NOR,({"red tooth","tooth"}) );
  set("long",
"這是螞蟻王的牙齒，可能是死後鬆掉的。\n"
);
        set_weight(12000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("volume",2);
                set("unit","把");
               set("value",6000);
                set("limit_str",32);
        }
                set("weapon_prop/parry",14); 
                set("weapon_prop/dodge",5); 
                set("weapon_prop/con",-4);
                set("weapon_prop/str",3);
                set("weapon_prop/dex",1);
init_dagger(50);
        setup();
}

