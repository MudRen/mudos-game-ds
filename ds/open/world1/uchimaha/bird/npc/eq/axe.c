#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
        set_name("伐木鐵斧", ({ "wood_axe","axe" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這柄鐵斧是專門用來伐木的。\n");
                set("material", "iron");
                set("limit_skill",10);
                set("limit_str",20);
        }
    set("weapon_prop/con",1);
    set("weapon_prop/dex",-1);
    set("weapon_prop/parry",3);
    set("weapon_prop/dodge",-3);
    init_axe(20);
    setup();
}

