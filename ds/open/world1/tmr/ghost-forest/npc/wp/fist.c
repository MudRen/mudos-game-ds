#include <weapon.h>
inherit FIST;

void create()
{
  set_name("鎖命殂掌",({"ghost fist","fist"}) );
  set("long",
"這是一個鐵手套，上面佈滿了紅紅綠綠的鱗片，模樣十分古怪，\n"
"在手套上方，有著三個鐵勾，勾成爪狀，以增強殺傷力。\n"
);
        set_weight(12000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
		set("volume",2);
                set("unit","把");
               set("value",2500);
                set("limit_str",40);
        }
                set("weapon_prop/parry",10);
               set("weapon_prop/con",-2);
                set("weapon_prop/str",1);
                set("weapon_prop/dex",1);
init_fist(55);
        setup();
}
