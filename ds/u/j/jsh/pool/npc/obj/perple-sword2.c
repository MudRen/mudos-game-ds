#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name("紫煌定風劍" NOR ,({"perple-light sword","sword"}));
set("long","紫煌定風劍，乃古英雄竭達羅與巨鵰激戰後之遺物，為何是遺物，可想而知。\n");
set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",6000);
set("limit_str",28);
set("limit_dex",30);
set("material","gold");
        }
        set("weapon_prop/hit",5);
        set("weapon_prop/int",-1);
        set("weapon_prop/str",2);
init_sword(45);
setup();
}

