#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
    set_name("九狐爪",({"nine-fox claw","claw"}) );
    set("long","九尾的爪子，殺傷力非常大，傳說只要配上這雙爪子，
連不會武功\的平常人也可以變成英雄。\n");
        set_weight(7000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","對");
        set("value",20000); 
        set("material","gold"); 
        }
        set("weapon_prop/dex", 4);
        set("weapon_prop/str", 3);
        init_fist(60);
        setup();
}

