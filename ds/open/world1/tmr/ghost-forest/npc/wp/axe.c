#include <weapon.h>
inherit AXE;

void create()
{
       set_name("無滅巨斧",({"hug axe","axe"}) );
  set("long",
"一把十分巨大厚重的斧頭，光是握柄就有成人手臂大小，斧面闊廣\n"
"近丈，看來非要膂力過人，才揮舞的動。\n"
);
        set_weight(30000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("unit","把");
		set("volume",6);
             set("value",2500);
                set("limit_str",40);
        }
                set("weapon_prop/parry",10);
                set("weapon_prop/dex",-2);
                set("weapon_prop/str",1);
		init_axe(60,TWO_HANDED);
        setup();
}
