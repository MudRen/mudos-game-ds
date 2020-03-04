#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SSERVER;
inherit SWORD;
void create()
{
set_name( CYN "神武劍" NOR ,({"god sword","sword"}));
set("long","這是一把神武歷代掌門人所使用的神兵利器。\n");
set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",5000);
set("limit_str",20);
set("limit_dex",15);
set("material","blacksteel");
        }
set("wield_msg","$N從腰間抽出一把發出萬丈光芒的$n，只聽見$n發出「嗡∼嗡∼∼」的聲音。\n");
set("unequip_msg","$N放下手中的$n,將$n插入劍鞘中。\n");
        set("weapon_prop/hit",10);
        set("weapon_prop/int",2);
        set("weapon_prop/str",1);
        set("weapon_prop/con",1);
        init_sword(69);
        set("replica_ob",__DIR__"godsword2.c");
setup();
}
