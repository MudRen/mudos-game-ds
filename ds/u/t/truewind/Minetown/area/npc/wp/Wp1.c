#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIR"血紅"NOR"長柄刀",({"Bloody meat-cutter","meat-cutter","cutter"}) );
        set_weight(500);
        set("long",@long
一把普通的長柄切肉刀，不過因為不常清洗的關係，上頭染滿了
鮮血，握在手上相當輕盈，不曉得是用什麼技術做成的？？
long
        );
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",300);
        set("unit","柄");
        set("wield_msg","$N趁趁手，握緊$n。\n");
        set("material","iron");
        init_blade(25);
        }
        setup();

}