#include <weapon.h>
#include <ansi.h>
inherit SWORD;


void create()
{
set_name( MAG "【隱天】" NOR,({"In-Tan sword","sword"}));
set("long","當年打造紅塵劍時，兩把劍中較好的一把，取名為【隱天】。\n");
set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",30000);
set("material","iron");
        }
init_sword(100);
set("weapon_prop/dex",100);
set("weapon_prop/str",100);
set("weapon_prop/con",100);
set("weapon_prop/int",100);
set("weapon_prop/hungchen-sword",50);
set("weapon_prop/parry",100);
set("weapon_prop/dodge",100);
set("weapon_prop/damage", 170);
        setup();
}
