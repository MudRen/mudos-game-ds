#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIW"神奇小光刀"NOR, ({ "magic_small_ blade","blade" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "神奇的小光刀。\n");
                set("value", 4000);
                set("material", "iron");
                set("wield_msg",
                HIY "$N舉起手中的$n"HIY+"，頓時$N的運氣好像變好了，令人[凍未條]啦。\n"
                NOR);
       
             }
    set("weapon_prop/con",10);
    set("weapon_prop/dex",10);
    set("weapon_prop/str",10);
    set("weapon_prop/int",10);
    init_blade(65);
    setup();
}

