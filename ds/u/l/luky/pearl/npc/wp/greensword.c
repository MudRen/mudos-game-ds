#include <weapon.h>

inherit SWORD;

void create()
{
set_name("綠晶劍",({"green sword","sword"}));
set("long","這是一把鑲有綠水晶的寶劍, 攻擊力似乎不錯。\n");
set_weight(24000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",4200);
set("sword",120);
set("material","gem");
        }
init_sword(720);
setup();
}
