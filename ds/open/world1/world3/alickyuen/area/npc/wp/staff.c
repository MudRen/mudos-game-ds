#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
        set_name(HIY "電擊棒" NOR,({"electric staff","staff"}) );
        set("long",
        "這是一把笨拙的棒子。\n"
        "但這把棒最特別之處就是會放電，若今它電到，就算不死也重傷。\n"
);
          set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
          set("value",500);
set("weapon_prop/hit", -2);
        }
 set("material","silver");
   set("weapon_prop/dodge",-2);
        init_staff(20);
        setup();
}
