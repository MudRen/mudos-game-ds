#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( HIC "嘻嘻劍" NOR ,({"cici sword","sword"}));
set("long","這是一把劍。\n");
set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "把");
              set("material","blacksteel");
             }
        set("wield_msg","$N從背後抽出一把$n，只見$N嘻嘻嘻的笑了起來。\n");
        set("unwield_msg","$N放下手中的$n，將$n小心的用布包起，放在背後。\n");
        set("weapon_prop/sou",2);
        set("weapon_prop/bar",2);
        set("weapon_prop/int",2);
init_sword(100);
setup();
}

