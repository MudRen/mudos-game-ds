#include <weapon.h>
inherit SWORD;

void create()
{
set_name("天師桃木劍",({"peach sword","sword"}));
set("long","這是一把道士用來制伏妖魔鬼怪的桃木劍。\n");
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
		set("value",2000);
set("volume",2);
        }
init_sword(20);
set("weapon_prop/hit",5);
set("weapon_prop/int",2);
         setup();
} 
