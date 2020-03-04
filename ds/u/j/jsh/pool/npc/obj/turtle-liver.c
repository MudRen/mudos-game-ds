#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(CYN"玄沉"HIR"龜膽"NOR, ({ "turtle-liver","liver" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "玄武神龜的巨膽，有多種的功\能，是等極的補品。\n");
                set("unit", "顆");
                set("value", 5000);  
                set("food_remaining",1);
                set("heal_hp",500+random(100+random(50)));   
                set("heal_ap",400+random(90+random(40)));
                set("heal_mp",300+random(80+random(30)));
        }
}


