#include <weapon.h>
inherit FIST;

void create()
{
  set_name("萬沙石爪",({"stone fist","fist"}) );
  set("long",
"這是石魔巨人所裝備的武器，由石子跟沙組成，防禦跟殺傷力\n"
"，都不可忽視。\n"
);
        set_weight(12000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("volume",2);
                set("unit","把");
               set("value",3000);
                set("limit_str",32);
        }
                set("weapon_prop/parry",12); 
                set("weapon_prop/dodge",-5);               set("weapon_prop/con",1);
                set("weapon_prop/str",2);
                set("weapon_prop/dex",-1);
init_fist(45);
        setup();
}

