#include <weapon.h>

#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIW"輕"HIG"風"HIW"劍"NOR, ({"wind sword","sword"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "把");
         set("long", "散發出陣陣涼風的劍,輕巧無比。\n");
         set("value", 200);
         set("wield_msg","$N旋風式的轉了轉左手,集風而上,呈出一把$n。\n");
         set("unwield_msg","$N左手一鬆,$n隨風散去了。\n");
         set("weapon_prop/con", -3);
         set("weapon_prop/dex", 4);
    }
    init_sword(64);
    setup();
}









