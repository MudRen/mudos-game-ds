#include <weapon.h>

#include <ansi.h>

inherit AXE;

void create()
{
    set_name(MAG"巨人斧"NOR, ({"big axe","axe"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "把");
         set("long", "一把巨型的斧頭,威力大,殺傷力可能也不小。\n");
         set("value", 150);
         set("wield_msg","$N把$n緊握在手上。\n");
         set("unwield_msg","$N把$n放下來。\n");
         set("weapon_prop/str", 3);
         set("weapon_prop/con", 1);
         set("weapon_prop/dex", 2);
         set("weapon_prop/int", 2); 
    }
    init_axe(65);
    setup();
}









