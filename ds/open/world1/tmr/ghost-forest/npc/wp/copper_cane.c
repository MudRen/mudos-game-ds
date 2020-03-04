#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
  set_name(YEL"黃銅棍"NOR,({"copper cane","cane"}) );
  set("long",
"一枝有丈六長的黃銅棍，通體有兒手臂大小，棍面盡是刻痕，看來佔戰\n"
"已久。棍身一頭隱隱刻著「噬魔」二字，不知帶有什麼含意。\n"
);
        set_weight(25000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","copper");
                set("unit","枝");
                set("value",5000);
                set("limit_level",20);
                set("weapon_prop/parry",10);
                set("weapon_prop/dex",-2);
        }
        init_staff(50);
        setup();
}
