#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( CYN "神武劍" NOR ,({"god sword","sword"}));
set("long","這是一把神武歷代掌門人所使用的神兵利器。\n");
set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",125000);
set("limit_str",20);
set("limit_dex",15);
        }
set("wield_msg","$N從腰間抽出一把發出萬丈光芒的$n，只聽見$n發出「嗡∼嗡∼∼」的聲音。\n");
set("unequip_msg","$N放下手中的$n,將$n插入劍鞘中。\n");
init_sword(55);
setup();
}
