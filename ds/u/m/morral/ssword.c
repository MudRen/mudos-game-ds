#include <weapon.h>
#include <ansi.h>

inherit SWORD;
void create()
{
set_name(HIG"精神劍"NOR,({"spirit sword","sword","spirit"}) );
set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long",HIG"這是一把極為平和的劍，說它是劍還不如說它是一團
能量。雖說這是一把防衛之劍，但是你可以感覺得到還有秘密隱藏在裡面。\n"NOR);
set("value",1);
init_sword(15);
                set("material", "energy");
set("wield_msg","$N裝備上$n，平和的力量從$N的手上散發出來。\n");
set("unwield_msg", "$N將手上的$n收起。\n");
}
setup();
}
int query_autoload() { return 1; }
  
