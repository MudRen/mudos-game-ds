#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR"血蛟膽"NOR, ({ "blood-snake liver","liver" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "血蛟的膽囊，可行全身之氣，舒筋活血[此物可 Max_Hp]。\n");
                set("unit", "顆");
                set("value", 4500);  
                set("food_remaining",1);
                set("heal_hp",3000);//全滿   
        }
}

